/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:57:59 by hidriouc          #+#    #+#             */
/*   Updated: 2024/02/24 18:18:29 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_pixel(int x, int y, t_fract *fractol)
{
	t_ncomplix	z;
	t_ncomplix	c;
	int 		i;
	int			collor;
	
	i = 0;
	(z.x = 0, z.y = 0);
	c.x= chang_Between(x, -2, 2, 0, size_x - 1);
	c.y= chang_Between(y, 2, -2, 0,	size_x - 1);
	while(i < iteration)
	{
		z = sum(power_tow(z),c);
		if((z.x * z.x) * (z.y * z.y) > ignore_it)
		{
			collor = chang_Between(i, BLACK, WHITE, 0, iteration);
			collor_pixel(x, y, collor, &fractol->img);
			return ;
		}
		i++;
	}
	collor_pixel(x, y, BLACK, &fractol->img);
}
void	draw_img(t_fract *fractol)
{
	int	x;
	int	y;

	y = 0;
	while(y < size_y)
	{
		x = 0;
		while(x < size_x)
		{
			draw_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connectoin, fractol->mlx_window,fractol->img.img_ptr, 0, 0);
}
void	mlx_error(t_fract	*fractol, char *s)
{
	ft_putstr_fd(s, 2);
	free(fractol);
	exit(EXIT_FAILURE);
}
void	fract_Mandl(t_fract *fractol)
{
	fractol->mlx_connectoin = mlx_init();
	if(!fractol->mlx_connectoin)
		mlx_error(fractol,"mlx_init() ERROR ");
	fractol->mlx_window = mlx_new_window(fractol->mlx_connectoin, size_x, size_y,fractol->name);
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connectoin, size_x, size_y);
	fractol->img.img_pixels = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bpp, &fractol->img.size_line, &fractol->img.endian);
	if(!fractol->mlx_window)
		mlx_error(fractol,"mlx_new_window ERROR");
	draw_img(fractol);
	mlx_loop(fractol->mlx_connectoin);
}
int main(int ac, char *av[])
{
	t_fract	fractol;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
	{
		fractol.name = av[1];
		fract_Mandl(&fractol);
	}
	else if(ac == 4 && !ft_strncmp(av[1], "Julia", 6))
	{
		
	}
	else
		ft_putstr_fd("number of argumments is longer then 5 !!", 1);
	return(0);
}
