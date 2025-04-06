/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-04 20:42:30 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-04 20:42:30 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> // para printf
#include "fdf.h"
#include "fdf.h"
#include "mlx.h"

void	clear_image(t_data *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < 720)
	{
		x = 0;
		while (x < 1280)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	*map;

	if (argc != 2)
		return (1);

	// 1. Cargamos el mapa desde el archivo .fdf
	map = read_map(argv[1]);
	if (!map)
		return (1);

	// 2. Iniciamos MiniLibX
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1280, 720, "FdF");

	// 3. Creamos una imagen donde pintaremos todo
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.line_len, &img.endian);

	// 4. Dibujamos el mapa (la malla de líneas)
	draw_map(map, &img);

	// 5. Ponemos la imagen en la ventana
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_hook(win, 2, 1L << 0, handle_key, NULL); // MAC
	mlx_hook(win, 17, 0, handle_close, NULL); // Cierra con la X

	// 6. Iniciamos el loop de eventos de MiniLibX
	mlx_loop(mlx);
	return (0);
}


