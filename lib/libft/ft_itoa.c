/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 18:40:42 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 22:23:52 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_is_negative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
	return ;
}

char			*ft_itoa(int n)
{
	int		mem;
	int		i;
	int		neg;
	char	*str;

	mem = n;
	i = 2;
	neg = 0;
	ft_is_negative(&n, &neg);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (mem /= 10)
		i++;
	i += neg;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	str[--i] = '\0';
	while (i--)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
