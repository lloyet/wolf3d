/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wall.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/14 23:43:13 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/22 04:21:10 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void					wall_destroy(t_wall *wall)
{
	ft_memdel((void**)&wall);
	return ;
}

t_wall					*new_wall(t_image *f0, t_image *f1, t_image *f2, t_image *f3)
{
	t_wall				*wall;

	if (!(wall = (t_wall*)ft_memalloc(sizeof(t_wall))))
		return (0);
	wall->face[0] = f0;
	wall->face[1] = f1;
	wall->face[2] = f2;
	wall->face[3] = f3;
	return (wall);
}

void					wall_set_face(t_wall *wall, int face, t_image *f)
{
	wall->face[face] = f;
	return ;
}

void					wall_uninit(t_wall **wall_buf)
{
	wall_destroy(wall_buf[0]);
	wall_destroy(wall_buf[1]);
	wall_destroy(wall_buf[2]);
	wall_destroy(wall_buf[3]);
	return ;
}

t_wall					**wall_init(t_image **tex_buff, int size)
{
	t_wall				**wall_buff;

	if (!(wall_buff = (t_wall**)ft_memalloc(sizeof(t_wall*) * size)))
		return (0);
	if (!(wall_buff[0] = new_wall(tex_buff[0], tex_buff[1], tex_buff[2], tex_buff[3])))
		return (0);
	if (!(wall_buff[1] = new_wall(tex_buff[0], tex_buff[1], tex_buff[2], tex_buff[3])))
		return (0);
	if (!(wall_buff[2] = new_wall(tex_buff[0], tex_buff[1], tex_buff[2], tex_buff[3])))
		return (0);
	if (!(wall_buff[3] = new_wall(tex_buff[0], tex_buff[1], tex_buff[2], tex_buff[3])))
		return (0);
	return (wall_buff);
}
