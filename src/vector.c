/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/13 20:38:38 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 20:38:38 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "../inc/wolf.h"

static mat2x2_t     rotY;

void                mat2x2_setRotY(angle_t *t)
{
    rotY.m[0][0] = t->fCos;
    rotY.m[0][1] = -t->fSin;
    rotY.m[1][0] = t->fSin;
    rotY.m[1][1] = t->fCos;
    return ;
}

void                vector_vecProduct(vector2D_t *vDest, vector2D_t *vMult)
{
    vDest->x = vDest->x*vMult->x;
    vDest->y = vDest->y*vMult->y;
    return ;
}

void                vector_rotY(vector2D_t *v)
{
    double          old_vx;

    old_vx = v->x;
    v->x = old_vx*rotY.m[0][0] + v->y*rotY.m[1][0];
    v->y = old_vx*rotY.m[0][1] + v->y*rotY.m[1][1];
    return ;
}

void                vector_reset(vector2D_t *v)
{
    v->x = 0;
    v->y = 0;
    return ;
}

void                vector_set(vector2D_t *v, double x, double y)
{
    v->x = x;
    v->y = y;
    return ;
}