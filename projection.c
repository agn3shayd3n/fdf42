/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-05 12:11:24 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-05 12:11:24 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// rotación en diagonal del terreno, como inclinar el plano hacia nosotras


void	axis_rotation(float *x, float *y, float *z, t_view *view)
{
	float	tmp;

	tmp = *y * cos(view->angle_x) - *z * sin(view->angle_x);
	*z = *y * sin(view->angle_y) + *z * cos(view->angle_y);
	*y = tmp;
	tmp = *x *cos(view->angle_y) + *z * sin(view->angle_y);
	*z = -*x * sin(view->angle_y) + *z * cos(view->angle_y);
	*x = tmp;
}

t_proj project(t_point p, t_view *view)
{
	t_proj proj;
	float x;
	float y;
	float rot_x;
	float rot_y;
	float	z;
	float	center_x;
	float	center_y;

	center_x = (float)view->map_width / 2;
	center_y = (float)view->map_height / 2;
	x = p.x - center_x;
	y = p.y - center_y;
	z = p.z;

	axis_rotation(&x, &y, &z, view);

	rot_x = x * cos(view->angle_z) - y * sin(view->angle_z);
	rot_y = x * sin(view->angle_z) + y * cos(view->angle_z);

	if (view->projection_mode == 0)
	{
		proj.x = ((rot_x - rot_y) * 10) * view->scale * 1.5 + view->offset_x;
		proj.y = ((rot_x + rot_y) * 5 - p.z * view->z_scale) * view->scale + view->offset_y;
	}
	else // birds eye
	{
		proj.x = rot_x * view->scale + view->offset_x;
		proj.y = rot_y * view->scale - p.z * (view->z_scale * 0.1) + view->offset_y;
	}
	proj.z = p.z;
	return (proj);
}


/*
t_proj project(t_point p, t_view *view)
{
	t_proj proj;

	proj.x = ((p.x - p.y) * 10) * view->scale * 1.5 + view->offset_x;
	proj.y = ((p.x + p.y) * 5 - p.z * view->z_scale) * view->scale + view->offset_y;
	proj.z = p.z;
	return (proj);
}
*/
