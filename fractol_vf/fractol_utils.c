/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:58:09 by hidriouc          #+#    #+#             */
/*   Updated: 2024/03/04 23:42:41 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_fract *fractol)
{
	fractol->iteration = 254;
	fractol->ignore_it = 4;
	fractol->x_move = 0.0;
	fractol->y_move = 0.0;
	fractol->zoom = 1.0;
}

void	inti_c(t_ncomplix *z, t_ncomplix *c, t_fract *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->x_julia;
		c->y = fractol->y_julia;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	collor_pixel(int x, int y, unsigned int collor, t_dataimg *img)
{
	unsigned int	i;

	i = (y * img->size_line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->img_pixels + i) = collor;
}

void	event_fract(t_fract *fractol)
{
	mlx_hook(fractol->mlx_window, 2, (1L << 0), handl_hey, fractol);
	mlx_hook(fractol->mlx_window, 4, (1L << 2), handl_mouse, fractol);
	mlx_hook(fractol->mlx_window, 17, (1L << 2), close_window, fractol);
}
