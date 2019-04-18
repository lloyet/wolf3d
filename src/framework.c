/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   framework.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:37:34 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 20:37:34 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

void                window_destroy(window_t *win)
{
    image_destroy(win->mlx_id, win->img);
    ft_memdel((void **)&win);
    return;
}

window_t            *new_window(void *mlx_id, int width, int heigh, char *title)
{
    window_t        *win;

    if (!(win = (window_t *)ft_memalloc(sizeof(window_t))))
        return (0);
    if (!(win->id = mlx_new_window(mlx_id, width, heigh, title)))
        return (0);
    if (!(win->img = new_image(mlx_id, width, heigh)))
        return (0);
    win->width = width;
    win->heigh = heigh;
    win->mlx_id = mlx_id;
    win->title = title;
    return (win);
}

void                framework_destroy(framework_t *framework)
{
    mlx_destroy_window(framework->id, framework->win->id);
    window_destroy(framework->win);
    ft_memdel((void **)&framework);
    return;
}

framework_t         *new_framework(void)
{
    framework_t     *mlx;

    if (!(mlx = (framework_t *)ft_memalloc(sizeof(framework_t))))
        return (0);
    if (!(mlx->id = mlx_init()))
        return (0);
    if (!(mlx->win = new_window(mlx->id, WIDTH, HEIGH, "WOLF")))
        return (0);
    return (mlx);
}