/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   angle.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <lloyet@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 03:48:03 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 03:50:58 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/wolf.h"

void				angle_destroy(t_angle *angle)
{
	ft_memdel((void**)&angle);
	return ;
}

t_angle				*new_angle(double f_theta)
{
	t_angle			*angle;

	if (!(angle = (t_angle*)ft_memalloc(sizeof(t_angle))))
		return (0);
	angle_reset(angle, f_theta);
	return (angle);
}

void				angle_reset(t_angle *angle, double f_theta)
{
	angle->f_theta = f_theta;
	angle->f_cos = cos(f_theta);
	angle->f_sin = sin(f_theta);
	return ;
}

double				t_angleo_degree(t_vector2d *v)
{
	return (fmodf(360.0 + atan2(v->y, v->x) / M_PI * 180.0, 360.0));
}

void				t_angleo_radian(t_vector2d *v, double deg)
{
	v->x = cos(deg * M_RAD);
	v->y = sin(deg * M_RAD);
	return ;
}
