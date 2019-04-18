/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   device.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 20:17:08 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 18:22:04 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

void                mouse_destroy(mouse_t *mouse)
{
    ft_memdel((void**)&mouse);
    return ;
}

mouse_t             *new_mouse(keyboard_t *keyboard)
{
    mouse_t         *mouse;

    if (!(mouse = (mouse_t*)ft_memalloc(sizeof(mouse_t))))
        return (0);
    mouse->keyboard = keyboard;
    return (mouse);
}

void                keyboard_destroy(keyboard_t *keyboard)
{
    ft_memdel((void**)&keyboard->regID);
    ft_memdel((void**)&keyboard);
    return ;
}

keyboard_t          *new_keyboard(int size)
{
    keyboard_t      *keyboard;

    if (!(keyboard = (keyboard_t*)ft_memalloc(sizeof(keyboard_t))))
        return (0);
    if (!(keyboard->regID = (uint8_t *)ft_memalloc(sizeof(uint8_t)*size)))
        return (0);
    return (keyboard);
}

int                 register_newKey(keyboard_t *keyboard, int key)
{
    if (keyboard->regSize < REG_KMASK_MAX)
        keyboard->regID[key] = ++keyboard->regSize;
    else
        return (0);
    return (1);
}