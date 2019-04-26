/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   engine.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:07:01 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 03:50:20 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void				device_register_keys(t_keyboard *k)
{
	register_new_key(k, KEY_ESCAPE);
	register_new_key(k, KEY_LEFT);
	register_new_key(k, KEY_RIGHT);
	register_new_key(k, KEY_W);
	register_new_key(k, KEY_S);
	register_new_key(k, KEY_SHIFT_LEFT);
	register_new_key(k, KEY_F1);
	register_new_key(k, KEY_F2);
	register_new_key(k, KEY_PAD_ADD);
	register_new_key(k, KEY_PAD_SUB);
	register_new_key(k, KEY_PAD_0);
	register_new_key(k, KEY_PAD_1);
}

void					engine_destroy(t_engine *e)
{
	ft_memdel((void**)e->wall_buff);
	texture_uninit(e->mlx->id, e->tex_buff);
	framework_destroy(e->mlx);
	keyboard_destroy(e->keyboard);
	mouse_destroy(e->mouse);
	entity_destroy(e->player);
	entity_destroy(e->ia);
	camera_destroy(e->cam);
	world_destroy(e->world);
	ft_memdel((void **)&e);
	exit(1);
}

t_engine				*new_engine(void)
{
	t_engine			*e;

	if (!(e = (t_engine *)ft_memalloc(sizeof(t_engine))))
		return (0);
	if (!(e->mlx = new_framework()))
		return (0);
	if (!(e->keyboard = new_keyboard(KEYBOARD_S)))
		return (0);
	if (!(e->mouse = new_mouse(e->keyboard)))
		return (0);
	if (!(e->cam = new_camera(P_SENSI, FOV_2, VIEW_MAX)))
		return (0);
	device_register_keys(e->keyboard);
	return (e);
}
