/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:58:42 by hidriouc          #+#    #+#             */
/*   Updated: 2024/03/05 02:22:59 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define X_SIZE	900
# define Y_SIZE	800

# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct s_ncomplix
{
	double	x;
	double	y;
}	t_ncomplix;

typedef struct s_dataimg
{
	void	*img_ptr;
	char	*img_pixels;
	int		bpp;
	int		size_line;
	int		endian;
}	t_dataimg;

typedef struct s_fract
{
	void		*mlx_connectoin;
	void		*mlx_window;
	char		*name;
	t_dataimg	img;

	double		iteration;
	double		ignore_it;
	double		x_move;
	double		y_move;
	double		zoom;
	double		x_julia;
	double		y_julia;
}	t_fract;

void		ft_putstr(char *str);
double		atodouble(char *str);
t_ncomplix	power_two(t_ncomplix z);
void		draw_img(t_fract *fractol);
void		init_data(t_fract *fractol);
void		event_fract(t_fract *fractol);
int			close_window(t_fract *fractol);
t_ncomplix	sum(t_ncomplix	c1, t_ncomplix	c2);
int			handl_hey(int key_sym, t_fract *fractol);
void		mlx_error(t_fract	*fractol, char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			handl_mouse(int Bttn, int x, int y, t_fract *fractol);
void		inti_c(t_ncomplix *z, t_ncomplix *c, t_fract *fractol);
void		collor_pixel(int x, int y, unsigned int collor, t_dataimg *img);
double		chang_between(double num, double n_min, double n_max, double max);
#endif