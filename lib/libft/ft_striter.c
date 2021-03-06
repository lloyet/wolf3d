/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 14:56:51 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 19:14:50 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				ft_striter(char *str, void (*f)(char *))
{
	char			*str_;

	str_ = str;
	while (*str_)
		f(str_++);
	return ;
}
