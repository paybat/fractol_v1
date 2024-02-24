/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:58:42 by hidriouc          #+#    #+#             */
/*   Updated: 2024/02/24 18:11:43 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_OL_H
# define FRACTOL_OL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

#define size_x 800
#define size_y 800
#define iteration 80
#define ignore_it 4

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define BLUE 0x0000FF

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
}	t_fract;

t_ncomplix	power_tow(t_ncomplix z);
void		ft_putstr_fd(char *s, int fd);
t_ncomplix	sum(t_ncomplix	c1, t_ncomplix	c2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		collor_pixel(int x, int y, unsigned int collor, t_dataimg *img);
double		chang_Between(int unscaledNum, int n_min, int n_max, int min, double max);
unsigned int	choose_color(int iter, int r, int g, int b);

#endif