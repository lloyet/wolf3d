/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   entity.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/30 14:27:37 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 18:23:58 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

void                entity_destroy(entity_t *e)
{
    ft_memdel((void**)&e);
    return ;
}

entity_t            *new_entity(double velDefault, uint8_t anchor)
{
    entity_t        *e;

    if (!(e = (entity_t*)ft_memalloc(sizeof(entity_t))))
        return (0);
    e->coord.x = -1;
    e->coord.y = -1;
    e->dir.x = -1;
    e->dir.y = 0;
    e->fVeloDef = velDefault;
    e->fVeloCur = velDefault;
    e->anchor = anchor;
    return (e);
}

void                entity_setLocation(entity_t *e, int x, int y)
{
    e->coord.x = x;
    e->coord.y = y;
    return ;
}

void                entity_setOrientation(entity_t *e, double deg)
{
    angle_toRadian(&e->dir, deg);
    return ;
}

void                entity_tryMove(world_t * w, entity_t *e)
{
    (void)w;
    vector2D_t      try;
    int             moveX;
    int             moveY;

    try.x = e->dir.x * e->vel.x;
    try.y = e->dir.y * e->vel.y;
    moveX = e->coord.x + try.x;
    moveY = (e->coord.y + try.y);
    if (!world_getObj(w, moveX, (int)e->coord.y))
        e->coord.x += try.x;
    if (!world_getObj(w, (int)e->coord.x, moveY))
        e->coord.y += try.y;
    return ;
}