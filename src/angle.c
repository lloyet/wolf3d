/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   angle.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 03:48:03 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 19:11:44 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

void                angle_destroy(angle_t *angle)
{
    ft_memdel((void**)&angle);
    return ;
}

angle_t             *new_angle(double fTheta)
{
    angle_t         *angle;

    if (!(angle = (angle_t*)ft_memalloc(sizeof(angle_t))))
        return (0);
    angle_reset(angle, fTheta);
    return (angle);
}

void                angle_reset(angle_t *angle, double fTheta)
{
    angle->fTheta = fTheta;
    angle->fCos = cos(fTheta);
    angle->fSin = sin(fTheta);
    return ;
}

double              angle_toDegree(vector2D_t *v)
{
    return (fmodf(360.0 + atan2(v->y, v->x) / M_PI * 180.0, 360.0));
}

void                angle_toRadian(vector2D_t *v, double deg)
{
    v->x = cos(deg * M_RAD);
    v->y = sin(deg * M_RAD);
    return ;
}