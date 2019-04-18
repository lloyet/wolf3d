/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 16:12:00 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 22:04:24 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	char	isnegative;
	int		nbr;

	i = 0;
	nbr = 0;
	isnegative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			isnegative = -1;
	while ((str[i] >= '0') && (str[i] <= '9'))
		nbr = nbr * 10 + str[i++] - '0';
	return (nbr * isnegative);
}
