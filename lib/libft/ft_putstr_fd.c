/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 13:51:05 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 19:05:42 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				ft_putstr_fd(char const *str, int fd)
{
	const char		*str_;

	str_ = str;
	while (*str_)
		write (1, str_++, fd);
	return ;
}
