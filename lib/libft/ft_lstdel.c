/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 19:21:38 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 19:56:42 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(list_t **alst, void (*del)(void *, size_t))
{
	list_t		*next;

	while (*alst)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next;
	}
	return ;
}
