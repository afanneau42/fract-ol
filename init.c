/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:31:23 by afanneau          #+#    #+#             */
/*   Updated: 2017/02/15 14:44:51 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_param(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "m") == 0 || ft_strcmp(argv[1], "j") == 0 ||
				ft_strcmp(argv[1], "b") == 0)
			return (0);
		else if (ft_strcmp(argv[1], "--help") == 0)
		{
			write_help_term();
			return (1);
		}
	}
	ft_putendl("usage : [m | j | b]");
	ft_putendl("        [--help]");
	return (1);
}

void	reset_data_m(t_frac *frac)
{
	frac->zoom = 500;
	frac->x = 0;
	frac->y = 0;
	frac->x1 = -2.1;
	frac->y1 = -1.2;
	frac->x2 = 0.6;
	frac->y2 = 1.2;
	frac->i_max = 50;
	frac->image_x = (frac->x2 - frac->x1) * frac->zoom;
	frac->image_y = (frac->y2 - frac->y1) * frac->zoom;
	frac->c_r = 0;
	frac->c_i = 0;
	frac->z_r = 0;
	frac->z_i = 0;
	frac->tmp = 0;
	frac->frac = 1;
	frac->i = 0;
	frac->c = 50;
	frac->col = 0;
}

void	reset_data_b(t_frac *frac)
{
	frac->zoom = 500;
	frac->x = 0;
	frac->y = 0;
	frac->x1 = -2.1;
	frac->y1 = -1.2;
	frac->x2 = 0.6;
	frac->y2 = 1.2;
	frac->i_max = 50;
	frac->image_x = (frac->x2 - frac->x1) * frac->zoom;
	frac->image_y = (frac->y2 - frac->y1) * frac->zoom;
	frac->c_r = 0.285;
	frac->c_i = 0.01;
	frac->z_r = 0;
	frac->z_i = 0;
	frac->tmp = 0;
	frac->e_var = 0;
	frac->frac = 3;
	frac->i = 0;
	frac->c = 50;
	frac->col = 0;
}

void	reset_data_j(t_frac *frac)
{
	frac->zoom = 500;
	frac->x = 0;
	frac->y = 0;
	frac->x1 = -1.35;
	frac->y1 = -1.2;
	frac->x2 = 1.35;
	frac->y2 = 1.2;
	frac->i_max = 100;
	frac->image_x = (frac->x2 - frac->x1) * frac->zoom;
	frac->image_y = (frac->y2 - frac->y1) * frac->zoom;
	frac->c_r = 0.285;
	frac->c_i = 0.01;
	frac->z_r = 0;
	frac->z_i = 0;
	frac->tmp = 0;
	frac->e_var = 0;
	frac->frac = 2;
	frac->i = 0;
	frac->c = 50;
	frac->col = 0;
}

void	init_struct(t_frac **frac, char f)
{
	*frac = malloc(sizeof(t_frac));
	(*frac)->ad = mlx_init();
	(*frac)->win = mlx_new_window((*frac)->ad, 1350, 1200, "Fract'ol");
	(*frac)->img_ad = mlx_new_image((*frac)->ad, 1350, 1200);
	(*frac)->bpp = malloc(sizeof(int) * 4);
	(*frac)->size_l = malloc(sizeof(int) * 1350 * 4);
	(*frac)->edi = malloc(sizeof(int));
	(*frac)->img_mem = mlx_get_data_addr((*frac)->img_ad,
			(*frac)->bpp, (*frac)->size_l, (*frac)->edi);
	if (f == 'm')
	{
		(*frac)->frac = 1;
		reset_data_m(*frac);
	}
	if (f == 'j')
	{
		(*frac)->frac = 2;
		reset_data_j(*frac);
	}
	if (f == 'b')
	{
		(*frac)->frac = 3;
		reset_data_b(*frac);
	}
}
