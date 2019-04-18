/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 14:36:57 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/31 17:53:02 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*str_;
	char	*str;

	size = ft_strlen(s1);
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str_ = str;
	while (*s1)
		*(str++) = *(s1++);
	*str = '\0';
	return (str_);
}
