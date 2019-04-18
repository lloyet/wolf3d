/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 17:33:21 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 17:39:44 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*dest_;

	dest_ = dest;
	while (*dest_)
		dest_++;
	while (*src && n--)
		*dest_++ = *src++;
	*dest_++ = '\0';
	return (dest);
}
