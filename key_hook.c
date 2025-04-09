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

#include "fdf.h"

static int	handle_zoom(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 24) // + MAC
		fdf->view.scale * = 1.1;
	else if (keycode == 27) // -
		fdf->view.scale * = 0.9;
	return (0);
}

static int	handle_arrows(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 124) // <-
		fdf->view.offset_x -= 30;
	else if (keycode == 123) // ->
		fdf->view.offset_x += 30;
	else if (keycode == 126)
		fdf->view.offset_y += 30; // V
	else if (keycode == 125) // ^
		fdf->view.offset_y -= 30;
	return (0);
}

static int	handle_axis(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 12) // Q
		fdf->view.angle_x += 0.1;
	else if (keycode == 14) // E
		fdf->view.angle_x -= 0.1;
	else if (keycode == 13) // W
		fdf->view.angle_y += 0.1;
	else if (keycode == 1) // S
		fdf->view.angle_y -= 0.1;
	return (0);
}

static int	create_window(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx, 1280, 720);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
	draw_map(fdf->map, &fdf->img, &fdf->view);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	instructions(fdf);
	return (0);
}

int	handle_key(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 53)
		exit(0);
	else if (keycode == 24 || keycode == 27)
		handle_zoom(keycode, param);
	else if (keycode >= 123 && keycode <= 126)
		handle_arrows(keycode, param);
	else if (keycode == 15) // R
		fdf->view.angle_z += 0.1;
	else if (keycode == 37) // L
		fdf->view.angle_z -= 0.1;
	else if (keycode == 11) // B
		fdf->view.projection_mode = !fdf->view.projection_mode;
	else if ((keycode == 1) || (keycode >= 12 && keycode <= 14))
		handle_axis(keycode, param);
	else if (keycode == 51) //reset
		fdf->view = fdf->reset_view;
	else if (keycode == 4) // H
		fdf->show_panel = !fdf->show_panel;
	create_window(param);
	return (0);
}
