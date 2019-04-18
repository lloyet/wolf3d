/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striteri.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 14:59:13 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 17:56:16 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int index;

	index = 0;
	while (s && f && *s)
		f(index++, s++);
	return ;
}
