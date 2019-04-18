/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 17:39:54 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 19:10:55 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	char	*dest_;
	size_t	dest_s;
	size_t	src_s;

	dest_s = ft_strlen(dest);
	src_s = ft_strlen(src);
	if (n < dest_s)
		return (n + src_s);
	dest_ = &dest[dest_s];
	while (*src && (dest_s + 1) < n--)
		*dest_++ = *src++;
	*dest_++ = '\0';
	return (dest_s + src_s);
}
