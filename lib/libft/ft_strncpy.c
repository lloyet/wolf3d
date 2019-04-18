/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/22 12:20:05 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 19:22:32 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dest, char const *src, size_t n)
{
	char			*dest_;

	dest_ = dest;
	while (n-- > 0)
		if (*src != 0)
			*dest++ = *src++;
		else
			*dest++ = 0;
	return (dest_);
}
