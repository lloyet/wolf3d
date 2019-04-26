/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/31 21:32:44 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/22 04:45:10 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static struct s_ray		r;

static void		ray_find_step(void)
{
	if (r.dir.x < 0)
	{
		r.step_x = -1;
		r.side_dist.x = (r.origin.x - r.map_x) * r.d_dist.x;
	}
	else
	{
		r.step_x = 1;
		r.side_dist.x = (r.map_x + 1.0 - r.origin.x) * r.d_dist.x;
	}
	if (r.dir.y < 0)
	{
		r.step_y = -1;
		r.side_dist.y = (r.origin.y - r.map_y) * r.d_dist.y;
	}
	else
	{
		r.step_y = 1;
		r.side_dist.y = (r.map_y + 1.0 - r.origin.y) * r.d_dist.y;
	}
	return ;
}

static void		ray_dda(t_world *w, int view_max)
{
	r.light = 0;
	r.d_dist.x = fabs(1.0 / r.dir.x);
	r.d_dist.y = fabs(1.0 / r.dir.y);
	ray_find_step();
	while (1)
	{
		if (r.side_dist.x < r.side_dist.y)
		{
			r.side_dist.x += r.d_dist.x;
			r.map_x += r.step_x;
			if (r.dir.x > 0)
				r.wall_side = 0;
			else
				r.wall_side = 2;
		}
		else
		{
			r.side_dist.y += r.d_dist.y;
			r.map_y += r.step_y;
			if (r.dir.y > 0)
				r.wall_side = 1;
			else
				r.wall_side = 3;
		}
		if (world_get_obj(w, r.map_x, r.map_y) > 0)
			break ;
		if (r.light > view_max - 1)
			break ;
		r.light++;
	}
	return ;
}

static void		ray_project(int *draw)
{
	r.wall_height = 0;
	if (r.wall_side != 0 && r.wall_side != 2)
		r.wall_proj_dist = (r.map_y - r.origin.y + (1 - r.step_y) / 2) / r.dir.y + 0.001;
	else
		r.wall_proj_dist = (r.map_x - r.origin.x + (1 - r.step_x) / 2) / r.dir.x + 0.001;
	r.wall_height = (int)(HEIGH / r.wall_proj_dist);
	draw[0] = -r.wall_height / 2 + HEIGH_2;
	if (draw[0] < 0)
		draw[0] = 0;
	draw[1] = r.wall_height / 2 + HEIGH_2;
	if (draw[1] > HEIGH - 1)
		draw[1] = HEIGH - 1;
	return ;
}

static void		t_rayexture(t_image *img, t_image *texture, int *draw, int *x)
{
	double		tex_x;
	double		tex_y;
	int			color;
	int			y;

	if (r.wall_side != 0 && r.wall_side != 2)
		tex_x = r.origin.x + r.wall_proj_dist * r.dir.x;
	else
		tex_x = r.origin.y + r.wall_proj_dist * r.dir.y;
	tex_x -= floor(tex_x);
	tex_x *= (double)texture->heigh;
	if (r.wall_side != 1 && r.dir.x > 0)
		tex_x = texture->width - tex_x - 1;
	if (r.wall_side != 0 && r.dir.y < 0)
		tex_x = texture->width - tex_x - 1;
	y = draw[0];
	while (y < draw[1])
	{
		tex_y = ((y - HEIGH_2 + r.wall_height * 0.5)
				* texture->heigh) / r.wall_height - 0.5;
		color = image_get_pixel(texture, tex_x, tex_y);
		//color &= (int)((double)color/r.light_ratio);
		image_pixel_put(img, *x, y, color);
		y++;
	}
	return ;
}

void			ray_cast(t_engine *e, t_camera *cam)
{
	double		camera_x;
	int			draw[2];
	int			x;

	r.origin.x = cam->entity->coord.x;
	r.origin.y = cam->entity->coord.y;
	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2.0 * x / (double)WIDTH - 1.0;
		ray_init(&r, cam, camera_x);
		ray_dda(e->world, cam->f_view_max);
		ray_project(draw);
		//r.light_ratio = (cam->f_view_max - r.light) / cam->f_view_max;
		r.light_ratio = (r.light - r.wall_proj_dist) / r.light;
		//r.light_ratio = (cam->f_view_max - r.wall_proj_dist) / cam->f_view_max;
		if (x == WIDTH_2)
			printf("r.StepX = %lf, r.StepY = %lf\n", r.dir.x, r.dir.y);
		//printf("\rlight = %d, proj = %lf, ratio = %lf", r.light, r.wall_proj_dist, r.light_ratio);
		r.tex_id = world_get_obj(e->world, r.map_x, r.map_y);
		if (r.tex_id > 0 && r.tex_id < 4)
			t_rayexture(e->mlx->win->img,
					e->wall_buff[r.tex_id]->face[r.wall_side], draw, &x);
		else if (r.tex_id > TEX_BUFF_S)
			ray_draw_wall(&r, e->mlx->win->img, draw, x);
		x++;
	}
	return ;
}
