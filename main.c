/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:20:15 by afanneau          #+#    #+#             */
/*   Updated: 2017/02/08 12:35:05 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_frac		*frac;

	if (check_param(argc, argv) == 0)
	{
		init_struct(&frac, argv[1][0]);
		ft_print(frac);
		mlx_key_hook(frac->win, event_key, (void*)frac);
		mlx_mouse_hook(frac->win, event_mouse, (void*)frac);
		mlx_hook(frac->win, 6, (1L << 6), event_mouse_pos, (void*)frac);
		mlx_hook(frac->win, 2, (1L << 0), event_key_press, (void*)frac);
		mlx_loop(frac->ad);
	}
	return (0);
}
