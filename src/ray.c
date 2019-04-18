/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/31 21:32:44 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 19:15:34 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static ray_t	r;

static void		ray_findStep(void)
{
	if (r.dir.x < 0)
	{
		r.stepX = -1;
		r.sideDist.x = (r.origin.x - r.mapX) * r.dDist.x;
	}
	else
	{
		r.stepX = 1;
		r.sideDist.x = (r.mapX + 1.0 - r.origin.x) * r.dDist.x;
	}
	if (r.dir.y < 0)
	{
		r.stepY = -1;
		r.sideDist.y = (r.origin.y - r.mapY) * r.dDist.y;
	}
	else
	{
		r.stepY = 1;
		r.sideDist.y = (r.mapY + 1.0 - r.origin.y) * r.dDist.y;
	}
	return ;
}

static void		ray_DDA(world_t *w, int view_max)
{
	r.light = 0;
	r.dDist.x = fabs(1.0 / r.dir.x);
	r.dDist.y = fabs(1.0 / r.dir.y);
	ray_findStep();
	while (1)
	{
		if (r.sideDist.x < r.sideDist.y)
		{
			r.sideDist.x += r.dDist.x;
			r.mapX += r.stepX;
			r.wallSide = 0;
		}
		else
		{
			r.sideDist.y += r.dDist.y;
			r.mapY += r.stepY;
			r.wallSide = 1;
		}
		if (world_getObj(w, r.mapX, r.mapY) > 0)
			break ;
		if (r.light > view_max)
			break ;
		r.light++;
	}
	return ;
}

static void		ray_project(int *draw)
{
	r.wallHeight = 0;
	if (r.wallSide != 0)
		r.wallProjDist = (r.mapY - r.origin.y +
		(1 - r.stepY) / 2) / r.dir.y + 0.001;
	else
		r.wallProjDist = (r.mapX - r.origin.x +
		(1 - r.stepX) / 2) / r.dir.x + 0.001;
	r.wallHeight = (int)(HEIGH / r.wallProjDist);
	draw[0] = -r.wallHeight / 2 + HEIGH_2;
	if (draw[0] < 0)
		draw[0] = 0;
	draw[1] = r.wallHeight / 2 + HEIGH_2;
	if (draw[1] > HEIGH - 1)
		draw[1] = HEIGH - 1;
	return ;
}

static void		ray_texture(image_t *img, image_t *texture, int *draw, int *x)
{
	double		texX;
	double		texY;
	int			color;
	int			y;

	if (r.wallSide != 1)
		texX = r.origin.y + r.wallProjDist * r.dir.y;
	else
		texX = r.origin.x + r.wallProjDist * r.dir.x;
	texX -= floor(texX);
	texX *= (double)texture->heigh;
	if (r.wallSide != 1 && r.dir.x > 0)
		texX = texture->width - texX - 1;
	if (r.wallSide != 0 && r.dir.y < 0)
		texX = texture->width - texX - 1;
	y = draw[0];
	while (y < draw[1])
	{
		texY = ((y - HEIGH_2 + r.wallHeight * 0.5) *
		texture->heigh) / r.wallHeight - 0.5;
		color = image_getPixel(texture, texX, texY);
		image_pixelPut(img, *x, y, color);
		y++;
	}
	return ;
}

void			ray_cast(engine_t *e, camera_t *cam)
{
	double		cameraX;
	int			draw[2];
	int			color;
	int			x;

	r.origin.x = cam->entity->coord.x;
	r.origin.y = cam->entity->coord.y;
	color = 0x00FFFF00;
	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2.0 * x / (double)WIDTH - 1.0;
		r.dir.x = cam->entity->dir.x + cam->plane.x * cameraX;
		r.dir.y = cam->entity->dir.y + cam->plane.y * cameraX;
		r.mapX = (int)r.origin.x;
		r.mapY = (int)r.origin.y;
		ray_DDA(e->world, cam->fView_max);
		ray_project(draw);
		r.texID = world_getObj(e->world, r.mapX, r.mapY);
		if (r.texID > 0 && r.texID < 4)
			ray_texture(e->mlx->win->img,
			e->wallBuff[r.texID]->face[r.wallSide], draw, &x);
		else if (r.texID > TEX_BUFF_S)
		{
			if (r.wallSide != 0)
				color /= 2;
			image_lineColorPut(e->mlx->win->img, x, draw[0], draw[1], color);
		}
		x++;
	}
	return ;
}
