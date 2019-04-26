/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:38:09 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 03:51:10 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static uint8_t			key_is_pressed(t_keyboard *keyboard, int key)
{
	return (keyboard->reg_key & (1 << keyboard->reg_id[key]) ? 1 : 0);
}

static void				event_catch_rot(t_entity *e, t_keyboard *k, t_camera *c)
{
	if (key_is_pressed(k, KEY_PAD_ADD) && c->f_view_max < 1024)
		c->f_view_max *= 2;
	else if (key_is_pressed(k, KEY_PAD_SUB) && c->f_view_max > 1)
		c->f_view_max /= 2;
	if (key_is_pressed(k, KEY_LEFT))
	{
		angle_reset(&e->angle, -c->f_sensi);
		mat2x2_set_rot_y(&e->angle);
		vector_rot_y(&e->dir);
		vector_rot_y(&c->plane);
	}
	else if (key_is_pressed(k, KEY_RIGHT))
	{
		angle_reset(&e->angle, c->f_sensi);
		mat2x2_set_rot_y(&e->angle);
		vector_rot_y(&e->dir);
		vector_rot_y(&c->plane);
	}
	return ;
}

static void				event_catch_move(t_entity *e, t_keyboard *k)
{
	if (key_is_pressed(k, KEY_SHIFT_LEFT))
		e->f_velo_cur = e->f_velo_def * 8.0;
	else
		e->f_velo_cur = e->f_velo_def;
	if (key_is_pressed(k, KEY_W))
	{
		e->vel.x = 2.0 * e->f_velo_cur;
		e->vel.y = 2.0 * e->f_velo_cur;
	}
	else if (key_is_pressed(k, KEY_S))
	{
		e->vel.x = -1.5 * e->f_velo_cur;
		e->vel.y = -1.5 * e->f_velo_cur;
	}
	return ;
}

void					event_docker(t_engine *engine, t_keyboard *k,
		t_camera *c)
{
	if (key_is_pressed(k, KEY_PAD_0))
		camera_dock(c, engine->player);
	else if (key_is_pressed(k, KEY_PAD_1))
		camera_dock(c, engine->ia);
	return ;
}

void					event_refresh(t_engine *engine, t_keyboard *keyboard,
		t_camera *cam)
{
	t_entity			*e;

	e = cam->entity;
	vector_reset(&e->vel);
	vector_reset(&e->straf);
	if (keyboard->reg_key > 1)
	{
		event_catch_move(e, keyboard);
		event_catch_rot(e, keyboard, cam);
		if (key_is_pressed(keyboard, KEY_ESCAPE))
			engine_destroy(engine);
		if (key_is_pressed(keyboard, KEY_F2))
			engine->mlx->win->menu = 1;
		else if (key_is_pressed(keyboard, KEY_F1))
			engine->mlx->win->menu = 0;
	}
	return ;
}
