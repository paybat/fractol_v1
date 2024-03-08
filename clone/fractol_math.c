/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:10:09 by hidriouc          #+#    #+#             */
/*   Updated: 2024/03/06 19:35:40 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	chang_between(double num, double n_min, double n_max, double max)
{
	int	min;

	min = 0;
	return ((n_max - n_min) * (num - min) / (max - min) + n_min);
}

static void	atodoable_help(char **str, int *singe)
{
	int	i;

	i = 0;
	while (*str[0] && *str[0] == ' ')
		str[0]++;
	if (*str[0] == '+' || *str[0] == '-')
	{
		if (*str[0] == '-')
			*singe *= -1;
		str[0]++;
	}
}

t_ncomplix	sum(t_ncomplix c1, t_ncomplix c2)
{
	t_ncomplix	r;

	r.x = c1.x + c2.x;
	r.y = c1.y + c2.y;
	return (r);
}

t_ncomplix	power_two(t_ncomplix z)
{
	t_ncomplix	r;

	r.x = (z.x * z.x) - (z.y * z.y);
	r.y = 2 * z.x * z.y;
	return (r);
}

double	atodouble(char *str)
{
	double	p_float;
	int		singe;
	float	div;

	div = 1;
	p_float = 0;
	singe = 1;
	atodoable_help(&str, &singe);
	while (*str && *str != '.' && (*str >= '0' && *str <= '9'))
	{
		p_float = (p_float * 10) + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		div /= 10;
		p_float = p_float + (*str - '0') * div;
		str++;
	}
	return (p_float * singe);
}
