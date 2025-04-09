/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-09 10:13:30 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-09 10:13:30 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	instructions(t_fdf *fdf)
{
	int		i;

	char	*lines[] = {
		"--- CONTROLES ---",
		"+ / -: Zoom",
		"Flechas: Mover mapa",
		"W/S: Rotar eje Y",
		"Q/E: Rotar eje X",
		"R/L: Rotar eje Z",
		"B: Cambiar proyeccion",
		"Backspace: Resetear vista",
		"H: Ocultar controles",
		NULL
	};
	i = 0;
	if (!fdf->show_panel)
		return ;
	while (lines[i])
	{
		mlx_string_put(fdf->mlx, fdf->win, 15, 20 + i * 20, 0xCCCCCC, lines[i]);
		i++;
	}
}