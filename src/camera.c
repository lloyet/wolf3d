/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   camera.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:37:27 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 20:37:27 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

void                camera_destroy(camera_t *c)
{
    ft_memdel((void**)&c);
    return ;
}

camera_t            *new_camera(double fSensi, double fov_2, double view)
{
    camera_t        *c;

    if (!(c = (camera_t*)ft_memalloc(sizeof(camera_t))))
        return (0);
    c->plane.x = 0;
    c->plane.y = tan(fov_2 * M_RAD);
    c->fSensi = fSensi;
    c->fView_max = view;
    return (c);
}

void                camera_dock(camera_t *c, entity_t *e)
{
    if (!e->anchor)
    {
        if (c->entity)
            c->entity->anchor = 0;
        c->entity = e;
        c->entity->anchor = 1;
    }
    else
        ft_putstr("[ERROR] DOCKER BUSY.\n");
    return ;
}

void                camera_view(window_t *w, mouse_t *m, camera_t *c)
{
    entity_t        *e;

    e = c->entity;
    if (m->x != WIDTH_2)
    {
        angle_reset(&e->angle, (m->x - WIDTH_2)*c->fSensi*0.025);
        mat2x2_setRotY(&e->angle);
        vector_rotY(&e->dir);
        vector_rotY(&c->plane);
        m->x = WIDTH_2;
    }
    mlx_mouse_move(w->id, WIDTH_2, HEIGH_2);
    mlx_mouse_hide();
    return ;
}
