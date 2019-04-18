/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 16:58:05 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 22:29:13 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))))
		return (NULL);
	ptr = str;
	while (*s1 || *s2)
		*ptr++ = (*s1) ? *s1++ : *s2++;
	return (str);
}
