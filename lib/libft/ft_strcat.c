/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 16:35:30 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 22:28:07 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*dest_;

	dest_ = dest;
	while (*dest_)
		dest_++;
	while (*src)
		*dest_++ = *src++;
	*dest_++ = '\0';
	return (dest);
}
