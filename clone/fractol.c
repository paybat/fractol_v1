/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:57:59 by hidriouc          #+#    #+#             */
/*   Updated: 2024/03/08 20:10:38 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(int x, int y, t_fract *fractol)
{
	t_ncomplix	z;
	t_ncomplix	c;
	int			i;
	int			collor;

	i = 0;
	z.x = chang_between(x, -2, 2, X_SIZE) * fractol->zoom + fractol->x_move;
	z.y = chang_between(y, 2, -2, Y_SIZE) * fractol->zoom + fractol->y_move;
	inti_c(&z, &c, fractol);
	while (i < fractol->iteration)
	{
		z = sum(power_two(z), c);
		if (sqrt((z.x * z.x) + (z.y * z.y)) > fractol->ignore_it)
		{
			collor = chang_between(i, BLACK, WHITE, fractol->iteration);
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
	while (y < Y_SIZE)
	{
		x = 0;
		while (x < X_SIZE)
		{
			draw_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connectoin, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}

void	fract(t_fract *fractol)
{
	fractol->mlx_connectoin = mlx_init();
	if (!fractol->mlx_connectoin)
		ft_putstr("mlx_init(), ERROR !!");
	fractol->mlx_window = mlx_new_window(fractol->mlx_connectoin, X_SIZE,
			Y_SIZE, fractol->name);
	if (!fractol->mlx_window)
		mlx_error(fractol, "mlx_new_window(), ERROR !!");
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connectoin, X_SIZE,
			Y_SIZE);
	if (!fractol->img.img_ptr)
		mlx_error(fractol, "mlx_new_image(), ERROR !!");
	fractol->img.img_pixels = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.size_line, &fractol->img.endian);
	if (!fractol->img.img_pixels)
		mlx_error(fractol, "mlx_get_data_addr(), ERROR");
	draw_img(fractol);
	event_fract(fractol);
}

void f()
{
	system("leaks fractol");
}

int	main(int ac, char *av[])
{
	t_fract	fractol;
	atexit(f);
	if ((X_SIZE <= 0 || X_SIZE > 5120) || (Y_SIZE <= 0 || Y_SIZE > 2880))
		return (ft_putstr("Error in size of window !!\n"), 1);
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		fractol.name = av[1];
		(init_data(&fractol), fract(&fractol));
		mlx_loop(fractol.mlx_connectoin);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		(ft_handelinput(av[2]), ft_handelinput(av[3]));
		fractol.name = av[1];
		fractol.x_julia = atodouble(av[2]);
		fractol.y_julia = atodouble(av[3]);
		(init_data(&fractol), fract(&fractol));
		mlx_loop(fractol.mlx_connectoin);
	}
	else
	{
		ft_putstr("bad argumments\n");
		ft_putstr("EX:\n./fractol mandelbrot\n./fractol julia v1 v2");
	}
	return (0);
}
