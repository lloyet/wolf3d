/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hook.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 20:07:09 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 22:08:01 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

int                     mouse_motion_hook(int x, int y, mouse_t *mouse)
{
    mouse->x = x;
    mouse->y = y;
    return (0);
}

int                     mouse_press_hook(int key, int x, int y, mouse_t *mouse)
{
    mouse->x = x;
    mouse->y = y;
    mouse->keyboard->regKey |= 1 << mouse->keyboard->regID[279+key];
    return (0);
}

int                     mouse_release_hook(int key, int x, int y, mouse_t *mouse)
{
    mouse->x = x;
    mouse->y = y;
    mouse->keyboard->regKey &= mouse->keyboard->regKey ^ (1 << mouse->keyboard->regID[279+key]);
    return (0);
}

int                     key_press_hook(int key, keyboard_t *keyboard)
{
    keyboard->regKey |= 1 << keyboard->regID[key];
    return (0);
}

int                     key_release_hook(int key, keyboard_t *keyboard)
{
    keyboard->regKey &= keyboard->regKey ^ (1 << keyboard->regID[key]);
    return (0);
}

int                     destroy_window_hook(engine_t *engine)
{
    engine_destroy(engine);
    return (0);
}