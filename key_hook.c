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
	(void)param;

	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}
int	handle_close(void *param)
{
	(void)param;
	
	exit(0);
	return (0);
}
