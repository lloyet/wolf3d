/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   world.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 20:26:19 by augberna     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 03:50:31 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void				world_destroy(t_world *w)
{
	ft_memdel((void**)&w->data);
	ft_memdel((void**)&w);
	return ;
}

t_world				*new_world(char *file_name)
{
	t_world			*w;

	if (!(w = (t_world*)ft_memalloc(sizeof(t_world))))
		return (0);
	w->file_name = file_name;
	w->spawn.x = -1;
	w->spawn.y = -1;
	return (w);
}

int					world_get_obj(t_world *w, int x, int y)
{
	return (w->data[x * w->width + y]);
}

void				world_set_spawn(t_world *w, int x, int y)
{
	w->spawn.x = x;
	w->spawn.y = y;
	return ;
}

t_world				*world_init(char *file_name)
{
	t_world			*w;

	if (!(w = new_world(file_name)))
	{
		ft_putstr("[ERROR] While Malloc.\n");
		return (0);
	}
	if (!parser_get_world_size(w))
	{
		ft_putstr("[ERROR] Bad Mapping Size. Expected same WIDTH.\n");
		return (0);
	}
	if (!(w->data = (int*)ft_memalloc(sizeof(int*) * w->heigh * w->width)))
	{
		ft_putstr("[ERROR] Bad Map Malloc.\n");
		return (0);
	}
	if (!parser_get_world(w))
	{
		ft_putstr("[ERROR] Fail To Open Fd.\n");
		return (0);
	}
	return (w);
}
