/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:49:56 by afanneau          #+#    #+#             */
/*   Updated: 2017/02/08 15:55:43 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ope_julia(t_frac *frac)
{
	while (frac->z_r * frac->z_r + frac->z_i *
			frac->z_i < 4 && frac->i < frac->i_max)
	{
		frac->tmp = frac->z_r;
		frac->z_r = frac->z_r * frac->z_r -
			frac->z_i * frac->z_i + frac->c_r;
		frac->z_i = 2 * frac->z_i * frac->tmp + frac->c_i;
		frac->i++;
	}
}

void	ope_mandel(t_frac *frac)
{
	while (frac->z_r * frac->z_r + frac->z_i *
			frac->z_i < 4 && frac->i < frac->i_max)
	{
		frac->tmp = frac->z_r;
		frac->z_r = frac->z_r * frac->z_r -
			frac->z_i * frac->z_i + frac->c_r;
		frac->z_i = 2 * frac->z_i * frac->tmp + frac->c_i;
		frac->i++;
	}
}

void	ope_ship(t_frac *frac)
{
	while (frac->z_r * frac->z_r + frac->z_i *
			frac->z_i < 4 && frac->i < frac->i_max)
	{
		frac->tmp = frac->z_r;
		frac->z_r = frac->z_r * frac->z_r -
			frac->z_i * frac->z_i + frac->c_r;
		frac->z_i = 2 * fabs(frac->z_i * frac->tmp) + frac->c_i;
		frac->i++;
	}
}
