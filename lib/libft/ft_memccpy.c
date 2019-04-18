/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 13:06:21 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 18:07:42 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n-- > 0)
		if (*(unsigned char *)src == (unsigned char)c &&
			*(unsigned char *)src &&
			(*(unsigned char *)dest++ = *(unsigned char *)src++))
			return (dest);
		else
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (NULL);
}
