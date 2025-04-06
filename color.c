/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-06 11:21:35 by agnesgar          #+#    #+#             */
/*   Updated: 2025-04-06 11:21:35 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z)
{
	if (z < 10)
		return (0x444444); // gris oscuro
	if (z < 30)
		return (0x777777); // gris medio
	if (z < 50)
		return (0xBBBBBB); // gris claro
	if (z < 70)
		return (0xFFFFFF); // blanco brillante
	if (z < 90)
		return (0xE0FFFF); // azul pastel (azure)
	if (z < 120)
		return (0xADD8E6); // azul cielo
	return (0x87CEEB);     // azul celeste vibrante ✨
}




