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

/*
void auto_fit_view(t_map *map, t_view *view, const char *filename)
{
	(void)map;
	(void)filename;

	view->scale = 25.0;        // Escala visual decente
	view->z_scale = view->scale * 1.0;      // Relieve moderado

	view->offset_x = 480;     // Mitad horizontal de una ventana 1280x720
	view->offset_y = 50;     // Mitad vertical

	printf("auto_fit_view: scale=%f, offset_x=%f, offset_y=%f\n",
		view->scale, view->offset_x, view->offset_y);
}
*/

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
	fdf.view.scale = 3.0;
	fdf.view.z_scale = 2.8;
	fdf.view.offset_x = 640;
	fdf.view.offset_y = 360;
	fdf.view.angle_z = 0;
	fdf.view.angle_x = 0;
	fdf.view.angle_y = 0;
	fdf.view.projection_mode = 0;
	fdf.view.map_width = fdf.map->width;
	fdf.view.map_height = fdf.map->height;

	// fdf.view.z_scale = 3.0;
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



