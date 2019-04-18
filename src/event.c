/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:38:09 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 20:38:09 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

static uint8_t          key_isPressed(keyboard_t *keyboard, int key)
{
    return (keyboard->regKey & (1 << keyboard->regID[key]) ? 1 : 0);
}

static void             event_catchRot(entity_t *e, keyboard_t *k, camera_t *c)
{
    if (key_isPressed(k, KEY_PAD_ADD) && c->fView_max < 1024)
        c->fView_max *= 2;
    else if (key_isPressed(k, KEY_PAD_SUB) && c->fView_max > 1)
        c->fView_max /= 2;
    if (key_isPressed(k, KEY_LEFT))
    {
        angle_reset(&e->angle, -c->fSensi);
        mat2x2_setRotY(&e->angle);
        vector_rotY(&e->dir);
        vector_rotY(&c->plane);
    }
    else if (key_isPressed(k, KEY_RIGHT))
    {
        angle_reset(&e->angle, c->fSensi);
        mat2x2_setRotY(&e->angle);
        vector_rotY(&e->dir);
        vector_rotY(&c->plane);
    }
    return ;
}

static void             event_catchMove(entity_t *e, keyboard_t *k)
{
    if (key_isPressed(k, KEY_SHIFT_LEFT))
        e->fVeloCur = e->fVeloDef*8.0;
    else
        e->fVeloCur = e->fVeloDef;
    if (key_isPressed(k, KEY_W))
    {
        e->vel.x = 2.0 * e->fVeloCur;
        e->vel.y = 2.0 * e->fVeloCur;
    }
    else if (key_isPressed(k, KEY_S))
    {
        e->vel.x = -1.5 * e->fVeloCur;
        e->vel.y = -1.5 * e->fVeloCur;
    }
    return ;
}

void                    event_docker(engine_t *engine, keyboard_t *k, camera_t *c)
{
    if (key_isPressed(k, KEY_PAD_0))
        camera_dock(c, engine->player);
    else if (key_isPressed(k, KEY_PAD_1))
        camera_dock(c, engine->IA);
    return ;
}

void                    event_refresh(engine_t *engine, keyboard_t *keyboard, camera_t *cam)
{
    entity_t            *e;

    e = cam->entity;
    vector_reset(&e->vel);
    vector_reset(&e->straf);
    if (keyboard->regKey > 1)
    {
        event_catchMove(e, keyboard);
        event_catchRot(e, keyboard, cam);
        if (key_isPressed(keyboard, KEY_ESCAPE))
            engine_destroy(engine);
        if (key_isPressed(keyboard, KEY_F2))
            engine->mlx->win->menu = 1;
        else if (key_isPressed(keyboard, KEY_F1))
            engine->mlx->win->menu = 0;
    }
    return ;
}