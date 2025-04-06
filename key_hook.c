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

int	handle_key(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == 53)
		exit(0);
	else if (keycode == 24) // + MAC
		fdf->view.scale *= 1.1;
	else if (keycode == 27) // -
		fdf->view.scale *=0.9;
	
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx, 1280, 720);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
		&fdf->img.line_len, &fdf->img.endian);
	draw_map(fdf->map, &fdf->img, &fdf->view);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	return (0);
}
int	handle_close(void *param)
{
	(void)param;
	
	exit(0);
	return (0);
}
