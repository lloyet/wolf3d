/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   world.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 00:48:48 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 00:49:04 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

void                world_destroy(world_t *w)
{
    ft_memdel((void**)&w->data);
    ft_memdel((void**)&w);
    return ;
}

world_t             *new_world(char *fileName)
{
    world_t         *w;

    if (!(w = (world_t*)ft_memalloc(sizeof(world_t))))
        return (0);
    w->fileName = fileName;
    w->spawn.x = -1;
    w->spawn.y = -1;
    return (w);
}

int                 world_getObj(world_t *w, int x, int y)
{
    return (w->data[x * w->width + y]);
}

void                world_setSpawn(world_t *w, int x, int y)
{
    w->spawn.x = x;
    w->spawn.y = y;
    return ;
}

world_t             *world_init(char *fileName)
{
    world_t         *w;

    if (!(w = new_world(fileName)))
    {
        ft_putstr("[ERROR] While Malloc.\n");
        return (0);
    }
    if (!parser_getWorldSize(w))
    {
        ft_putstr("[ERROR] Bad Mapping Size. Expected same WIDTH.\n");
        return (0);
    }
    if (!(w->data = (int*)ft_memalloc(sizeof(int*)*w->heigh*w->width)))
    {
        ft_putstr("[ERROR] Bad Map Malloc.\n");
        return (0);
    }
    if (!parser_getWorld(w))
    {
        ft_putstr("[ERROR] Fail To Open Fd.\n");
        return (0);
    }
    return (w);
}