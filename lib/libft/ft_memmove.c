/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/29 15:12:30 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 15:40:10 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	void	*dest_;
	void	*src_;

	dest_ = (void *)dest + (n - 1);
	src_ = (void *)src + (n - 1);
	if (dest > src)
		while (n--)
			*(char *)dest_-- = *(char *)src_--;
	else if (dest < src)
		ft_memcpy(dest, src, n);
	return (dest);
}
