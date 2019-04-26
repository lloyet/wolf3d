/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_utils.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 03:04:15 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/22 02:01:05 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void			ray_draw_wall(t_ray *r, t_image *img, int *draw, int x)
{
	int			color;

	color = 0x00FFFF00;
	if (r->wall_side != 0)
		color /= 2;
	color *= r->light_ratio;
	while (draw[0] < draw[1])
		image_pixel_put(img, x, draw[0]++, color);
	return ;
}

void			ray_init(t_ray *r, t_camera *c, double camera_x)
{
	r->dir.x = c->entity->dir.x + c->plane.x * camera_x;
	r->dir.y = c->entity->dir.y + c->plane.y * camera_x;
	r->map_x = (int)r->origin.x;
	r->map_y = (int)r->origin.y;
	return ;
}
