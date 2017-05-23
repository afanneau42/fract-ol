/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:19:16 by afanneau          #+#    #+#             */
/*   Updated: 2017/02/08 16:36:09 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	write_help(t_frac *frac)
{
	mlx_string_put(frac->ad, frac->win, 450, 300, 0x00FFFF00, "Help");
	mlx_string_put(frac->ad, frac->win, 850, 300, 0x00FFFFFF, "H");
	mlx_string_put(frac->ad, frac->win, 450, 350, 0x00FFFF00, "Zoom");
	mlx_string_put(frac->ad, frac->win, 850, 350, 0x00FFFFFF,
			"Scroll up/down or Left click");
	mlx_string_put(frac->ad, frac->win, 450, 400, 0x00FFFF00,
			"Enable/Disable Julia's variations");
	mlx_string_put(frac->ad, frac->win, 850, 400, 0x00FFFFFF, "V");
	mlx_string_put(frac->ad, frac->win, 450, 450, 0x00FFFF00, "Color");
	mlx_string_put(frac->ad, frac->win, 850, 450, 0x00FFFFFF, "C");
	mlx_string_put(frac->ad, frac->win, 450, 500, 0x00FFFF00, "Accuracy");
	mlx_string_put(frac->ad, frac->win, 850, 500, 0x00FFFFFF, "+/-");
	mlx_string_put(frac->ad, frac->win, 450, 550, 0x00FFFF00, "Change fractal");
	mlx_string_put(frac->ad, frac->win, 850, 550, 0x00FFFFFF, "1 2 3");
	mlx_string_put(frac->ad, frac->win, 450, 750, 0x00FFFF00,
			"Exit (But you really don't want to !)");
	mlx_string_put(frac->ad, frac->win, 850, 750, 0x00FFFFFF, "ESC");
}

void	write_help_term(void)
{
	ft_putendl("************** HELP SECTION **************");
	ft_putendl("\nFractals available :");
	ft_putendl("\tmandelbrot   : m");
	ft_putendl("\tjulia        : j");
	ft_putendl("\tburning ship : b");
	ft_putendl("\nControls :");
	ft_putendl("\tzoom : left click or scroll up");
	ft_putendl("\taccuracy : +/-");
	ft_putendl("\tturn on/off Julia's variations : V");
	ft_putendl("\tcolor : C");
	ft_putendl("\thelp : H");
	ft_putendl("\texit : ESC");
	ft_putendl("\n*****************************************");
}
