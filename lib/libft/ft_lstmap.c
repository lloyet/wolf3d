/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 20:38:49 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 19:57:45 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

list_t			*ft_lstmap(list_t *lst, list_t *(*f)(list_t *elem))
{
	list_t		*new;
	list_t		*list;

	list = (*f)(lst);
	new = list;
	while ((lst = lst->next))
	{
		if (!(list->next = (*f)(lst)))
		{
			free(list->next);
			return (0);
		}
		list = list->next;
	}
	return (new);
}
