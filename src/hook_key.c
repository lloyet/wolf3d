/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hook_key.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/17 02:53:12 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 03:50:20 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

int				key_press_hook(int key, t_keyboard *keyboard)
{
	keyboard->reg_key |= 1 << keyboard->reg_id[key];
	return (0);
}

int				key_release_hook(int key, t_keyboard *keyboard)
{
	keyboard->reg_key &= keyboard->reg_key ^ (1 << keyboard->reg_id[key]);
	return (0);
}

int				destroy_window_hook(t_engine *engine)
{
	engine_destroy(engine);
	return (0);
}
