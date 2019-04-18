/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdelone.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 19:06:20 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 01:26:43 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(list_t **alst, void (*del)(void *, size_t))
{
	(*del)((*alst)->content, (*alst)->size);
	ft_memdel((void **)alst);
	return ;
}
