/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:19:20 by afanneau          #+#    #+#             */
/*   Updated: 2017/02/08 16:07:47 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_print(t_frac *frac)
{
	frac->frac == 1 ? ft_print_m(frac) : 0;
	frac->frac == 2 ? ft_print_j(frac) : 0;
	frac->frac == 3 ? ft_print_b(frac) : 0;
}

void		ft_print_b(t_frac *frac)
{
	frac->x = 0;
	while (frac->x < frac->image_x)
	{
		frac->y = 0;
		while (frac->y < frac->image_y)
		{
			frac->c_r = frac->x / frac->zoom + frac->x1;
			frac->c_i = frac->y / frac->zoom + frac->y1;
			frac->z_r = 0;
			frac->z_i = 0;
			frac->i = 0;
			ope_ship(frac);
			if (frac->i == frac->i_max)
				img_pixel_put(frac->x, frac->y, 0x00FFFFFF, frac);
			else
				img_pixel_put(frac->x, frac->y,
						frac->i * 255 * 256 * 256 / frac->c, frac);
			frac->y++;
		}
		frac->x++;
	}
	mlx_clear_window(frac->ad, frac->win);
	mlx_put_image_to_window(frac->ad, frac->win, frac->img_ad, 0, 0);
	mlx_string_put(frac->ad, frac->win, 620, 10, 0x00FFFFFF, "Burning Ship");
}

void		ft_print_m(t_frac *frac)
{
	frac->x = 0;
	while (frac->x < frac->image_x)
	{
		frac->y = 0;
		while (frac->y < frac->image_y)
		{
			frac->c_r = frac->x / frac->zoom + frac->x1;
			frac->c_i = frac->y / frac->zoom + frac->y1;
			frac->z_r = 0;
			frac->z_i = 0;
			frac->i = 0;
			ope_mandel(frac);
			if (frac->i == frac->i_max)
				img_pixel_put(frac->x, frac->y, 0x00FFFFFF, frac);
			else
				img_pixel_put(frac->x, frac->y,
						frac->i * 255 * 256 * 256 / frac->c, frac);
			frac->y++;
		}
		frac->x++;
	}
	mlx_clear_window(frac->ad, frac->win);
	mlx_put_image_to_window(frac->ad, frac->win, frac->img_ad, 0, 0);
	mlx_string_put(frac->ad, frac->win, 625, 10, 0x00FFFFFF, "Mandelbrot");
}

void		ft_print_j(t_frac *frac)
{
	frac->x = 0;
	while (frac->x < frac->image_x)
	{
		frac->y = 0;
		while (frac->y < frac->image_y)
		{
			frac->z_r = frac->x / frac->zoom + frac->x1;
			frac->z_i = frac->y / frac->zoom + frac->y1;
			frac->i = 0;
			ope_julia(frac);
			if (frac->i == frac->i_max)
				img_pixel_put(frac->x, frac->y, 0x00FFFFFF, frac);
			else
				img_pixel_put(frac->x, frac->y,
						frac->i * 255 * 256 * 256 / frac->c, frac);
			frac->y++;
		}
		frac->x++;
	}
	mlx_clear_window(frac->ad, frac->win);
	mlx_put_image_to_window(frac->ad, frac->win, frac->img_ad, 0, 0);
	mlx_string_put(frac->ad, frac->win, 650, 10, 0x00FFFFFF, "Julia");
}

void		img_pixel_put(int x, int y, int color, t_frac *frac)
{
	frac->img_mem[x * 4 + y * 1350 * 4] = color & 255;
	frac->img_mem[1 + x * 4 + y * 1350 * 4] = (color >> 8) & 255;
	frac->img_mem[2 + x * 4 + y * 1350 * 4] = (color >> 16) & 255;
}
