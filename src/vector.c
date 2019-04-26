/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 20:36:03 by augberna     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 05:06:23 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

static struct s_mat2x2		rot_y;

void				mat2x2_set_rot_y(t_angle *t)
{
	rot_y.m[0][0] = t->f_cos;
	rot_y.m[0][1] = -t->f_sin;
	rot_y.m[1][0] = t->f_sin;
	rot_y.m[1][1] = t->f_cos;
	return ;
}

void				vector_vec_product(t_vector2d *v_dest, t_vector2d *v_mult)
{
	v_dest->x = v_dest->x * v_mult->x;
	v_dest->y = v_dest->y * v_mult->y;
	return ;
}

void				vector_rot_y(t_vector2d *v)
{
	double			old_vx;

	old_vx = v->x;
	v->x = old_vx * rot_y.m[0][0] + v->y * rot_y.m[1][0];
	v->y = old_vx * rot_y.m[0][1] + v->y * rot_y.m[1][1];
	return ;
}

void				vector_reset(t_vector2d *v)
{
	v->x = 0;
	v->y = 0;
	return ;
}

void				vector_set(t_vector2d *v, double x, double y)
{
	v->x = x;
	v->y = y;
	return ;
}
