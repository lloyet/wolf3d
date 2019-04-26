/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/15 01:06:33 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/22 03:44:00 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static int				refresh_stack(t_engine *e)
{
	e->old.tv_sec = e->cur.tv_sec;
	e->old.tv_usec = e->cur.tv_usec;
	ray_cast(e, e->cam);
	mlx_put_image_to_window(e->mlx->id, e->mlx->win->id, e->mlx->win->img->id,
			0, 0);
	debug_display(e);
	image_clear(e->mlx->win->img);
	gettimeofday(&e->cur, NULL);
	if (e->cur.tv_usec < e->old.tv_usec)
		e->mlx->frame = (e->old.tv_usec - e->cur.tv_usec) / 1000000.0;
	else
		e->mlx->frame = (e->cur.tv_usec - e->old.tv_usec) / 1000000.0;
	event_docker(e, e->keyboard, e->cam);
	event_refresh(e, e->keyboard, e->cam);
	t_entityry_move(e->world, e->cam->entity);
	camera_view(e->mlx->win, e->mouse, e->cam);
	return (0);
}

static int				init_engine(t_engine *e, char *str)
{
	if (!(e->world = world_init(str)))
		return (0);
	if (!(e->player = new_entity(P_VELO, 0)))
		return (0);
	if (!(e->ia = new_entity(IA_VELO, 0)))
		return (0);
	if (!texture_init(e->mlx->id, e->tex_buff))
		return (0);
	if (!(e->wall_buff = wall_init(e->tex_buff, 4)))
		return (0);
	return (1);
}

static void				init_hook(t_engine *e)
{
	mlx_hook(e->mlx->win->id,
			MOTIONNOTIFY, POINTERMOTIONMASK, mouse_motion_hook, e->mouse);
	mlx_hook(e->mlx->win->id,
			KEYPRESS, KEYPRESSMASK, key_press_hook, e->keyboard);
	mlx_hook(e->mlx->win->id,
			BUTTONPRESS, BUTTONPRESSMASK, mouse_press_hook, e->mouse);
	mlx_hook(e->mlx->win->id,
			KEYRELEASE, KEYRELEASEMASK, key_release_hook, e->keyboard);
	mlx_hook(e->mlx->win->id,
			BUTTONRELEASE, BUTTONRELEASEMASK, mouse_release_hook, e->mouse);
	mlx_hook(e->mlx->win->id,
			DESTROYNOTIFY, STRUCTURENOTIFYMASK, destroy_window_hook, e);
	mlx_loop_hook(e->mlx->id, refresh_stack, e);
	mlx_loop(e->mlx->id);
	return ;
}

int						main(int argc, char **argv)
{
	t_engine			*e;

	if (argc != 2)
	{
		ft_putstr("[ERROR] Bad Arguments.\nExpected: ./WOLF ./map\n");
		return (0);
	}
	if (!(e = new_engine()))
		return (0);
	if (!(init_engine(e, argv[1])))
		return (0);
	entity_set_location(e->player, e->world->spawn.x, e->world->spawn.y);
	entity_set_location(e->ia, 20, 20);
	camera_dock(e->cam, e->player);
	init_hook(e);
	return (0);
}
