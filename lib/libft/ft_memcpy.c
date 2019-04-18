/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 13:44:03 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 19:21:24 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	void			*dest_;

	dest_ = dest;
	while (n-- > 0)
		*(char *)dest++ = *(char *)src++;
	return (dest_);
}
