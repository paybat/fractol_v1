/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:30:38 by hidriouc          #+#    #+#             */
/*   Updated: 2024/03/08 20:09:46 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(void)
{
	exit(EXIT_FAILURE);
}

int	handl_mouse(int Bttn, int x, int y, t_fract *fractol)
{
	(void)x;
	(void)y;
	if (Bttn == 5)
	{
		fractol->zoom *= 0.80;
	}
	else if (Bttn == 4)
	{
		fractol->zoom *= 1.80;
	}
	draw_img(fractol);
	return (0);
}

int	handl_hey(int key, t_fract *fractol)
{
	if (key == 53 || key == 7)
		close_window();
	else if (key == 124)
		fractol->x_move -= 0.055;
	else if (key == 123)
		fractol->x_move += 0.055;
	else if (key == 125)
		fractol->y_move += 0.055;
	else if (key == 126)
		fractol->y_move -= 0.055;
	else if (key == 69)
		fractol->iteration += 1;
	else if (key == 78)
		fractol->iteration -= 1;
	draw_img(fractol);
	return (0);
}
