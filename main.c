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

void	auto_fit_view(t_map *map, t_view *view)
{
	int		x, y;
	float	min_x = 1e9, max_x = -1e9;
	float	min_y = 1e9, max_y = -1e9;
	t_proj	p;

	// Usa una scale temporal para hacer la proyección y calcular dimensiones
	view->scale = 1.0;
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			p = project(map->points[x][y], view);
			if (p.x < min_x) min_x = p.x;
			if (p.x > max_x) max_x = p.x;
			if (p.y < min_y) min_y = p.y;
			if (p.y > max_y) max_y = p.y;
			y++;
		}
		x++;
	}

	float	map_width = max_x - min_x;
	float	map_height = max_y - min_y;

	// Calcula el mejor zoom para que quepa en la ventana con márgenes
	float zoom_x = 1280 / map_width;
	float zoom_y = 720 / map_height;
	view->scale = fminf(zoom_x, zoom_y) * 0.8; // 80% para margen

	// Recalcula para el nuevo zoom y centra
	min_x = 1e9, max_x = -1e9;
	min_y = 1e9, max_y = -1e9;
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			p = project(map->points[x][y], view);
			if (p.x < min_x) min_x = p.x;
			if (p.x > max_x) max_x = p.x;
			if (p.y < min_y) min_y = p.y;
			if (p.y > max_y) max_y = p.y;
			y++;
		}
		x++;
	}
	view->offset_x = (1280 - (max_x + min_x)) / 2;
	view->offset_y = (720 - (max_y + min_y)) / 2;
}


int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (1);

	// 1. Cargar el mapa
	printf("Cargando mapa...\n");
	fdf.map = read_map(argv[1]);
	if (!fdf.map)
		return (1);

	// 2. Iniciar MiniLibX
	printf("Iniciando MLX...\n");
	fdf.mlx = mlx_init();
	printf("Creando ventana...\n");
	fdf.win = mlx_new_window(fdf.mlx, 1280, 720, "FdF");

	// 3. Crear imagen en memoria
	printf("Creando imagen...\n");
	fdf.img.img = mlx_new_image(fdf.mlx, 1280, 720);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img,
			&fdf.img.bpp, &fdf.img.line_len, &fdf.img.endian);

	// 4. Inicializar vista (zoom + posición)
	printf("Preparando vista...\n");
	fdf.view.z_scale = 3.0;
	auto_fit_view(fdf.map, &fdf.view);

	// 5. Dibujar mapa
	draw_map(fdf.map, &fdf.img, &fdf.view);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);

	// 6. Eventos
	mlx_hook(fdf.win, 2, 1L << 0, handle_key, &fdf); // Teclado
	mlx_hook(fdf.win, 17, 0, handle_close, &fdf);    // Cerrar ventana

	// 7. Bucle de eventos
	printf("Entrando en loop...\n");
	mlx_loop(fdf.mlx);
	return (0);
}



