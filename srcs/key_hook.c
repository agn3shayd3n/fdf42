/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-06 13:00:25 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-06 13:00:25 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	handle_zoom(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 6)
		fdf->view.scale *= 1.1;
	else if (keycode == 7)
		fdf->view.scale *= 0.9;
	return (0);
}

static int	handle_arrows(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 123)
		fdf->view.offset_x -= 30;
	else if (keycode == 124)
		fdf->view.offset_x += 30;
	else if (keycode == 125)
		fdf->view.offset_y += 30;
	else if (keycode == 126)
		fdf->view.offset_y -= 30;
	return (0);
}

static int	handle_axis(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 13)
		fdf->view.angle_x += 0.1;
	else if (keycode == 1)
		fdf->view.angle_x -= 0.1;
	else if (keycode == 14)
		fdf->view.angle_y += 0.1;
	else if (keycode == 12)
		fdf->view.angle_y -= 0.1;
	return (0);
}

int	handle_key(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 53)
		exit(0);
	else if (keycode == 6 || keycode == 7)
		handle_zoom(keycode, param);
	else if (keycode >= 123 && keycode <= 126)
		handle_arrows(keycode, param);
	else if (keycode == 37)
		fdf->view.angle_z += 0.1;
	else if (keycode == 15)
		fdf->view.angle_z -= 0.1;
	else if (keycode == 11)
		fdf->view.projection_mode = !fdf->view.projection_mode;
	else if ((keycode == 1) || (keycode >= 12 && keycode <= 14))
		handle_axis(keycode, param);
	else if (keycode == 51)
		fdf->view = fdf->reset_view;
	else if (keycode == 4)
		fdf->show_panel = !fdf->show_panel;
	create_window(param);
	return (0);
}
