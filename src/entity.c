/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   entity.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/30 14:27:37 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/27 00:50:14 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void				entity_destroy(t_entity *e)
{
	ft_memdel((void**)&e);
	return ;
}

t_entity			*new_entity(double vel_default, uint8_t anchor)
{
	t_entity		*e;

	if (!(e = (t_entity*)ft_memalloc(sizeof(t_entity))))
		return (0);
	e->coord.x = -1;
	e->coord.y = -1;
	e->dir.x = -1;
	e->dir.y = 0;
	e->f_velo_def = vel_default;
	e->f_velo_cur = vel_default;
	e->anchor = anchor;
	return (e);
}

void				entity_set_location(t_entity *e, int x, int y)
{
	e->coord.x = x;
	e->coord.y = y;
	return ;
}

void				entity_set_orientation(t_entity *e, double deg)
{
	t_angleo_radian(&e->dir, deg);
	return ;
}

void				entity_try_move(t_world *w, t_entity *e)
{
	t_vector2d		try;
	int				move_x;
	int				move_y;

	(void)w;
	try.x = e->dir.x * e->vel.x;
	try.y = e->dir.y * e->vel.y;
	move_x = e->coord.x + try.x;
	move_y = (e->coord.y + try.y);
	if (!world_get_obj(w, move_x, (int)e->coord.y))
		e->coord.x += try.x;
	if (!world_get_obj(w, (int)e->coord.x, move_y))
		e->coord.y += try.y;
	return ;
}
