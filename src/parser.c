/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/15 20:39:28 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 03:50:31 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void			parser_get_world_(t_world *w, char *str, int i)
{
	int				j;
	char			*str_;

	j = 0;
	str_ = str;
	while (*str_)
	{
		if (*str_ > '/' && *str_ < ':')
			w->data[i * w->width + j++] = *str_ - '0';
		else if (*str_ == 'X')
			world_set_spawn(w, i - 0.5, j++ - 0.5);
		str_++;
	}
	return ;
}

int					parser_get_world(t_world *w)
{
	char			*str;
	int				fd;
	int				i;

	if ((fd = open(w->file_name, O_RDONLY)) < 0)
		return (0);
	i = 0;
	while (get_next_line(fd, &str) > 0)
	{
		parser_get_world_(w, str, i);
		i++;
		free(str);
	}
	return (1);
}

static void			parser_get_world_size_(char *str, int *l)
{
	char			*str_;

	str_ = str;
	while (*str_)
	{
		if (*str_ > '/' && *str_ < ':')
			*l += 1;
		str_++;
	}
	return ;
}

int					parser_get_world_size(t_world *w)
{
	int				fd;
	int				old_l;
	int				l;
	char			*str;

	if ((fd = open(w->file_name, O_RDONLY)) < 0)
		return (0);
	l = 0;
	w->width = 0;
	w->heigh = 0;
	while (get_next_line(fd, &str) > 0)
	{
		old_l = l;
		l = 0;
		parser_get_world_size_(str, &l);
		if (old_l != w->width)
			return (-1);
		w->width = l;
		w->heigh++;
		free(str);
	}
	return (1);
}
