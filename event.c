/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:20:23 by afanneau          #+#    #+#             */
/*   Updated: 2017/03/29 17:20:48 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		event_mouse(int key, int x, int y, void *frac)
{
	if (key == 1 || key == 5)
	{
		((t_frac*)frac)->zoom *= RATIO;
		zoom(x, y, frac, 1);
		ft_print((t_frac*)frac);
	}
	if (key == 4)
	{
		((t_frac*)frac)->zoom /= RATIO;
		zoom(x, y, frac, -1);
		ft_print((t_frac*)frac);
	}
	return (0);
}

void	zoom(int x, int y, t_frac *frac, int zm)
{
		frac->x1 -= ((double)x / 1350 * (2.7 *
		(500 / frac->zoom)) * (RATIO - 1)) * (-zm);
	frac->x2 += ((double)x / 1350 *
		(2.7 * (500 / frac->zoom)) * (RATIO - 1)) * (zm);
	frac->y1 -= ((double)y / 1200 *
		(2.4 * (500 / frac->zoom)) * (RATIO - 1)) * (-zm);
	frac->y2 += ((double)y / 1200 *
		(2.4 * (500 / frac->zoom)) * (RATIO - 1)) * (zm);
	if (frac->i_max > 25)
		frac->i_max += zm * 1;
}

int		event_mouse_pos(int x, int y, void *frac)
{
	if (((t_frac*)frac)->frac == 2 && ((t_frac*)frac)->e_var == 1)
	{
		((t_frac*)frac)->c_r = (double)x / 675 * 0.02 + 0.285;
		((t_frac*)frac)->c_i = (double)y / 600 * 0.005 + 0.01;
	}
	((t_frac*)frac)->col == 1 ? ((t_frac*)frac)->c = x / 100 : 0;
	ft_print((t_frac*)frac);
	return (0);
}

int		event_key(int key, void *frac)
{
	key == 18 ? reset_data_m((t_frac*)frac) : 0;
	key == 19 ? reset_data_j((t_frac*)frac) : 0;
	key == 20 ? reset_data_b((t_frac*)frac) : 0;
	key == 53 ? exit(0) : 0;
	if (key == 8)
		((t_frac*)frac)->col == 1 ? ((t_frac*)frac)->col-- :
			((t_frac*)frac)->col++;
	if (key == 34)
	{
		((t_frac*)frac)->i_max += 10;
		ft_print((t_frac*)frac);
	}
	if (key == 9 && ((t_frac*)frac)->frac == 2)
		((t_frac*)frac)->e_var == 1 ? ((t_frac*)frac)->e_var-- :
			((t_frac*)frac)->e_var++;
	ft_print((t_frac*)frac);
	return (0);
}

int		event_key_press(int key, void *frac)
{
	if (key == 4)
	{
		mlx_clear_window(((t_frac*)frac)->ad, ((t_frac*)frac)->win);
		write_help((t_frac*)frac);
	}
	if (key == 78)
		((t_frac*)frac)->i_max > 25 ? ((t_frac*)frac)->i_max-- : 0;
	if (key == 69)
		((t_frac*)frac)->i_max < 200 ? ((t_frac*)frac)->i_max++ : 0;
	return (0);
}
