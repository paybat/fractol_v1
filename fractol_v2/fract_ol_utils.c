/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:58:09 by hidriouc          #+#    #+#             */
/*   Updated: 2024/03/04 04:11:42 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void	collor_pixel(int x, int y, unsigned int collor, t_dataimg *img)
{
	unsigned int i;
	
	i = (y * img->size_line) + (x * (img->bpp / 8));
	*(unsigned int*)(img->img_pixels + i) = collor;
}

void	event_fract(t_fract *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, handl_hey, fractol);
	mlx_hook(fractol->mlx_window, ButtonPress, ButtonPressMask, handl_mouse, fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify, ButtonPressMask,close_window , fractol);
}