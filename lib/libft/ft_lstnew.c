/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 19:03:25 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 20:01:02 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "./libft.h"

list_t				*ft_lstnew(const void *content, size_t size)
{
	list_t			*new_list;

	if (!(new_list = (list_t *)ft_memalloc(sizeof(list_t))))
		return (0);
	if (!(new_list->content = (void *)ft_memalloc(size)))
		return (new_list);
	ft_memcpy(new_list->content, content, size);
	new_list->size = size;
	return (new_list);
}
