/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 17:39:56 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 22:34:24 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	k;
	size_t	j;
	size_t	i;
	char	**ret;

	i = 0;
	j = 0;
	if (!s || !c || !(ret = (char **)ft_memalloc(sizeof(char *) *
		(ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			k = 0;
			while (s[i + k] != '\0' && s[i + k] != c)
				k++;
			ret[j++] = ft_strsub(s, i, k);
			i += k;
		}
	}
	ret[j] = 0;
	return (ret);
}
