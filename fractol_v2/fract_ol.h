/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:58:42 by hidriouc          #+#    #+#             */
/*   Updated: 2024/03/04 05:22:54 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_OL_H
# define FRACTOL_OL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <math.h>

#ifndef y_size
#define y_size 800
#endif

#ifndef x_size
#define x_size 900
#endif

#define BLACK 0x000000
#define WHITE 0xFFFFFF


#define KeyPress		2
#define ButtonPress		4
#define DestroyNotify	17

#define KeyPressMask	(1L<<0)
#define ButtonPressMask	(1L<<2)

#define XK_Left		124
#define XK_Up		125
#define XK_Right	123
#define XK_Down		126
#define XK_plus		69
#define XK_minus	78

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
	double		julia_x;
	double		julia_y;
}	t_fract;

double		atodouble(char *str);
t_ncomplix	sum(t_ncomplix	c1, t_ncomplix	c2);
t_ncomplix	power_two(t_ncomplix z);
void		init_data(t_fract *fractol);
void		event_fract(t_fract *fractol);
void		draw_img(t_fract *fractol);
int			close_window(t_fract *fractol);
void		collor_pixel(int x, int y, unsigned int collor, t_dataimg *img);
double		chang_Between(double Num, double n_min, double n_max, double min, double max);
int			handl_hey(int key_sym, t_fract *fractol);
int			handl_mouse(int Bttn, int x, int y, t_fract *fractol);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void	inti_c(t_ncomplix *z, t_ncomplix *c, t_fract *fractol);

#endif