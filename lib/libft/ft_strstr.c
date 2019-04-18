/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 19:40:32 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 21:15:19 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	if (!ft_strlen(haystack))
		return (NULL);
	i = 0;
	j = 0;
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
			if (!needle[j++ + 1])
				return ((char *)&haystack[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
