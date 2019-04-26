/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   misc.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 21:12:24 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 03:50:41 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void				debug_display(t_engine *e)
{
	if (e->mlx->win->menu)
	{
		mlx_string_put(e->mlx->id, e->mlx->win->id, 0, 0, 0x0000FF22,
				ft_strjoin("FPS: ", ft_itoa((1.0 / e->mlx->frame))));
		mlx_string_put(e->mlx->id, e->mlx->win->id, 0, 20, 0x0000FF22,
				ft_strjoin("X: ", ft_itoa(e->cam->entity->coord.x)));
		mlx_string_put(e->mlx->id, e->mlx->win->id, 100, 20, 0x0000FF22,
				ft_strjoin("Y: ", ft_itoa(e->cam->entity->coord.y)));
		mlx_string_put(e->mlx->id, e->mlx->win->id, 0, 40, 0x0000FF22,
				ft_strjoin("Facing: ",
					ft_itoa(t_angleo_degree(&e->cam->entity->dir))));
		mlx_string_put(e->mlx->id, e->mlx->win->id, 0, 60, 0x0000FF22,
				ft_strjoin("Render Distance: ", ft_itoa(e->cam->f_view_max)));
	}
	return ;
}
