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

t_proj	project(t_point p, t_view *view)
{
	t_proj proj;

	proj.x = ((p.x - p.y) * 10) * view->scale + view->offset_x;
	proj.y = ((p.x + p.y) * 5 - p.z * view->z_scale) * view->scale + view->offset_y;
	proj.z = p.z;
	return (proj);
}

/*
t_proj	project(t_point p)
{
	t_proj	proj;
	float	scale;
	float	z_scale;
	int		offset_x;
	int		offset_y;

	scale = 0.160;
	z_scale = 2.8;
	offset_x = 640;
	offset_y = 200;

	proj.x = ((p.x - p.y) * 10) * scale * 1.5 + offset_x;
	proj.y = ((p.x + p.y) * 5 - p.z * z_scale) * scale + offset_y;
	proj.z = p.z;
	return (proj);
}
*/