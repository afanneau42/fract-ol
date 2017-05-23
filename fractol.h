/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:27:13 by afanneau          #+#    #+#             */
/*   Updated: 2017/02/15 14:47:51 by afanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>
# include "minilibx/mlx.h"

# define RATIO 1.2

typedef	struct	s_frac
{
	void		*ad;
	void		*win;
	void		*img_ad;

	int			frac;
	int			i;

	double		x;
	double		y;

	double		x1;
	double		y1;

	double		x2;
	double		y2;

	int			i_max;

	double		image_x;
	double		image_y;

	double		c_r;
	double		c_i;

	double		z_r;
	double		z_i;

	int			*bpp;
	int			*size_l;
	int			*edi;
	char		*img_mem;

	double		zoom;
	double		tmp;
	double		c;
	int			col;

	int			e_var;
}				t_frac;

void			init_struct(t_frac **frac, char f);
void			reset_data_j(t_frac *frac);
void			reset_data_m(t_frac *frac);
void			reset_data_b(t_frac *frac);
int				check_param(int argc, char **argv);

void			img_pixel_put(int x, int y, int color, t_frac *frac);
void			img_pixel_add(int x, int y, t_frac *frac);
void			ft_print(t_frac *frac);
void			ft_print_m(t_frac *frac);
void			ft_print_j(t_frac *frac);
void			ft_print_b(t_frac *frac);

void			zoom(int x, int y, t_frac *frac, int zm);
void			write_help(t_frac *frac);
void			write_help_term(void);

int				event_key(int key, void *frac);
int				event_key_press(int key, void *frac);
int				event_mouse(int key, int x, int y, void *frac);
int				event_mouse_pos(int x, int y, void *frac);

void			ope_julia(t_frac *frac);
void			ope_mandel(t_frac *frac);
void			ope_ship(t_frac *frac);

#endif
