/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   engine.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:07:01 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 18:42:30 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

static void             device_registerKeys(keyboard_t *k)
{
    register_newKey(k, KEY_ESCAPE);
    register_newKey(k, KEY_LEFT);
    register_newKey(k, KEY_RIGHT);
    register_newKey(k, KEY_W);
    register_newKey(k, KEY_S);
    register_newKey(k, KEY_SHIFT_LEFT);
    register_newKey(k, KEY_F1);
    register_newKey(k, KEY_F2);
    register_newKey(k, KEY_PAD_ADD);
    register_newKey(k, KEY_PAD_SUB);
    register_newKey(k, KEY_PAD_0);
    register_newKey(k, KEY_PAD_1);
    return ;
}

void                    engine_destroy(engine_t *e)
{
    ft_memdel((void**)e->wallBuff);
    texture_uninit(e->mlx->id, e->texBuff);
    framework_destroy(e->mlx);
    keyboard_destroy(e->keyboard);
    mouse_destroy(e->mouse);
    entity_destroy(e->player);
    entity_destroy(e->IA);
    camera_destroy(e->cam);
    world_destroy(e->world);
    ft_memdel((void **)&e);
    exit(1);
    return;
}

engine_t                *new_engine(void)
{
    engine_t            *e;

    if (!(e = (engine_t *)ft_memalloc(sizeof(engine_t))))
        return (0);
    if (!(e->mlx = new_framework()))
        return (0);
    if (!(e->keyboard = new_keyboard(KEYBOARD_S)))
        return (0);
    if (!(e->mouse = new_mouse(e->keyboard)))
        return (0);
    if (!(e->cam = new_camera(P_SENSI, FOV_2, VIEW_MAX)))
        return (0);
    device_registerKeys(e->keyboard);
    return (e);
}