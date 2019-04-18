/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wall.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/14 23:43:13 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 22:32:35 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

void                    wall_destroy(wall_t *wall)
{
    ft_memdel((void**)&wall);
    return ;
}

wall_t                  *new_wall(image_t *f0, image_t *f1)
{
    wall_t              *wall;

    if (!(wall = (wall_t*)ft_memalloc(sizeof(wall_t))))
        return (0);
    wall->face[0] = f0;
    wall->face[1] = f1;
    return (wall);
}

void                    wall_uninit(wall_t **wallBuf)
{
    wall_destroy(wallBuf[0]);
    wall_destroy(wallBuf[1]);
    wall_destroy(wallBuf[2]);
    wall_destroy(wallBuf[3]);
    return ;
}

wall_t                  **wall_init(image_t **texBuff, int size)
{
    wall_t              **wallBuff;

    if (!(wallBuff = (wall_t**)ft_memalloc(sizeof(wall_t*)*size)))
        return (0);
    if (!(wallBuff[0] = new_wall(texBuff[0], texBuff[2])))
        return (0);
    if (!(wallBuff[1] = new_wall(texBuff[0], texBuff[3])))
        return (0);
    if (!(wallBuff[2] = new_wall(texBuff[1], texBuff[0])))
        return (0);
    if (!(wallBuff[3] = new_wall(texBuff[0], texBuff[1])))
        return (0);
    return (wallBuff);
}