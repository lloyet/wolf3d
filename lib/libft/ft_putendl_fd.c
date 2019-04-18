/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 13:57:31 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 22:24:55 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if ((char *)s == NULL)
		return ;
	while (*s)
		ft_putchar_fd(*(char *)s++, fd);
	ft_putchar_fd('\n', fd);
	return ;
}
