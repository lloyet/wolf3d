/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 01:06:33 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 19:12:33 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static int              refresh_stack(engine_t *e)
{
    e->old.tv_sec = e->cur.tv_sec;
    e->old.tv_usec = e->cur.tv_usec;
    ray_cast(e, e->cam);
    mlx_put_image_to_window(e->mlx->id, e->mlx->win->id, e->mlx->win->img->id, 0, 0);
    debug_display(e);
    image_clear(e->mlx->win->img);
    gettimeofday(&e->cur, NULL);
    if (e->cur.tv_usec < e->old.tv_usec)
        e->mlx->frame = (e->old.tv_usec - e->cur.tv_usec)/1000000.0;
    else
        e->mlx->frame = (e->cur.tv_usec - e->old.tv_usec)/1000000.0;
    event_docker(e, e->keyboard, e->cam);
    event_refresh(e, e->keyboard, e->cam);
    entity_tryMove(e->world, e->cam->entity);
    camera_view(e->mlx->win, e->mouse, e->cam);
    return (0);
}

static int              init_engine(engine_t *e, char *str)
{
    if (!(e->world = world_init(str)))
        return (0);
    if (!(e->player = new_entity(P_VELO, 0)))
        return (0);
    if (!(e->IA = new_entity(IA_VELO, 0)))
        return (0);
    if (!texture_init(e->mlx->id, e->texBuff))
        return (0);
    if (!(e->wallBuff = wall_init(e->texBuff, 4)))
        return (0);
    return (1);
}

static void             init_hook(engine_t *e)
{
    mlx_hook(e->mlx->win->id, MotionNotify, PointerMotionMask, mouse_motion_hook, e->mouse);
    mlx_hook(e->mlx->win->id, KeyPress, KeyPressMask, key_press_hook, e->keyboard);
    mlx_hook(e->mlx->win->id, ButtonPress, ButtonPressMask, mouse_press_hook, e->mouse);
    mlx_hook(e->mlx->win->id, KeyRelease, KeyReleaseMask, key_release_hook, e->keyboard);
    mlx_hook(e->mlx->win->id, ButtonRelease, ButtonReleaseMask, mouse_release_hook, e->mouse);
    mlx_hook(e->mlx->win->id, DestroyNotify, StructureNotifyMask, destroy_window_hook, e);
    mlx_loop_hook(e->mlx->id, refresh_stack, e);
    mlx_loop(e->mlx->id);
    return ;
}

int                     main(int argc, char **argv)
{
    engine_t            *e;

    if (argc != 2)
        return (0);
    if (!(e = new_engine()))
        return (0);
    if (!(init_engine(e, argv[1])))
        return (0);
    entity_setLocation(e->player, e->world->spawn.x, e->world->spawn.y);
    entity_setLocation(e->IA, 20, 20);
    camera_dock(e->cam, e->player);
    init_hook(e);
    return (0);
}