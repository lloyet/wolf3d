/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 19:23:50 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 19:40:22 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;
	char	*s_;

	n = ft_strlen(s);
	s_ = (char *)&s[n];
	while (s_ != s)
		if (*s_-- == (char)c)
			return ((char *)++s_);
	if (*s_ == (char)c)
		return ((char *)s_);
	return (NULL);
}
