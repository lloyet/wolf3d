/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   camera.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:37:27 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/22 03:27:24 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void				camera_destroy(t_camera *c)
{
	ft_memdel((void**)&c);
	return ;
}

t_camera			*new_camera(double f_sensi, double fov_2, double view)
{
	t_camera		*c;

	if (!(c = (t_camera*)ft_memalloc(sizeof(t_camera))))
		return (0);
	c->plane.x = 0;
	c->plane.y = tan(fov_2 * M_RAD);
	c->f_sensi = f_sensi;
	c->f_view_max = view;
	return (c);
}

void				camera_dock(t_camera *c, t_entity *e)
{
	if (!e->anchor)
	{
		if (c->entity)
			c->entity->anchor = 0;
		c->entity = e;
		c->entity->anchor = 1;
	}
	else
		ft_putstr("[ERROR] DOCKER BUSY.\n");
	return ;
}

void				camera_view(t_window *w, t_mouse *m, t_camera *c)
{
	t_entity		*e;

	e = c->entity;
	if (m->x != WIDTH_2)
	{
		angle_reset(&e->angle, (m->x - WIDTH_2) * c->f_sensi * 0.025);
		mat2x2_set_rot_y(&e->angle);
		vector_rot_y(&e->dir);
		vector_rot_y(&c->plane);
		m->x = WIDTH_2;
	}
	mlx_mouse_move(w->id, WIDTH_2, HEIGH_2);
	mlx_mouse_hide();
	return ;
}
