/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:57:59 by hidriouc          #+#    #+#             */
/*   Updated: 2024/03/04 05:08:13 by hidriouc         ###   ########.fr       */
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
	z.x = chang_Between(x, -2, 2, 0, x_size) * fractol->zoom + fractol->x_move;
	z.y = chang_Between(y, 2, -2, 0, y_size) * fractol->zoom + fractol->y_move;
	inti_c(&z, &c, fractol);
	while(i < fractol->iteration)
	{
		z = sum(power_two(z),c);
		if((z.x * z.x) + (z.y * z.y) > 4)
		{
			collor = chang_Between(i, BLACK, WHITE, 0, fractol->iteration);
			collor_pixel(x, y, collor, &fractol->img);
			return ;
		}
		i++;
	}
	collor_pixel(x, y, WHITE, &fractol->img);
}
void	draw_img(t_fract *fractol)
{
	int	x;
	int	y;

	y = 0;
	while(y < y_size)
	{
		x = 0;
		while(x < x_size)
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
	free(fractol);
	exit(EXIT_FAILURE);
}
void	fract(t_fract *fractol)
{
	fractol->mlx_connectoin = mlx_init();
	if(!fractol->mlx_connectoin)
		mlx_error(fractol,"mlx_init() ERROR ");
	fractol->mlx_window = mlx_new_window(fractol->mlx_connectoin, x_size, y_size,fractol->name);
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connectoin, x_size, y_size);
	fractol->img.img_pixels = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bpp, &fractol->img.size_line, &fractol->img.endian);
	if(!fractol->mlx_window)
		mlx_error(fractol,"mlx_new_window ERROR");
	draw_img(fractol);
	event_fract(fractol);
	
}
int main(int ac, char *av[])
{
	t_fract	fractol;

	if (x_size > 5120 || y_size > 2880)
		return (1);
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
	{
		fractol.name = av[1];
		init_data(&fractol);
		fract(&fractol);
		mlx_loop(fractol.mlx_connectoin);
	}
	else if(ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractol.name = av[1];
		fractol.julia_x = atodouble(av[2]);
		fractol.julia_y = atodouble(av[3]);
		init_data(&fractol);
		fract(&fractol);
		mlx_loop(fractol.mlx_connectoin);
	}
	else
		perror("number of argumments is longer then 5 !!");
	return(0);
}
