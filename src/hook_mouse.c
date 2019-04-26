/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hook_mouse.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 02:53:30 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 03:49:36 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

int						mouse_motion_hook(int x, int y, t_mouse *mouse)
{
	mouse->x = x;
	mouse->y = y;
	return (0);
}

int						mouse_press_hook(int key, int x, int y, t_mouse *mouse)
{
	mouse->x = x;
	mouse->y = y;
	mouse->keyboard->reg_key |= 1 << mouse->keyboard->reg_id[279 + key];
	return (0);
}

int						mouse_release_hook(int key, int x, int y,
		t_mouse *mouse)
{
	mouse->x = x;
	mouse->y = y;
	mouse->keyboard->reg_key &= mouse->keyboard->reg_key ^
		(1 << mouse->keyboard->reg_id[279 + key]);
	return (0);
}
