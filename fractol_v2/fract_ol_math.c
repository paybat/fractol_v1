/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:10:09 by hidriouc          #+#    #+#             */
/*   Updated: 2024/03/04 04:00:37 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	chang_Between(double Num, double n_min, double n_max, double min, double max)
{
	return ((n_max - n_min) * (Num - min) / (max - min) + n_min);
}
t_ncomplix	sum(t_ncomplix	c1, t_ncomplix	c2)
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
	int		p_int;
	int		singe;
	float		div;

	p_int = 0;
	div = 1;
	p_float = 0;
	singe = 1;
	while (*str && *str == ' ')
		str++;
	if(*str == '+' || *str == '-')
	{
		if (*str == '-')
			singe *= -1;
		str++;
	}
	while(*str && *str != '.' && (*str >= '0' && *str <= '9'))
	{
		p_int = (p_int * 10) + (*str - '0');
		str++;
	}
	if(*str == '.')
		str++;
	while(*str && (*str >= '0' && *str <= '9'))
	{
		div /= 10;
		p_float = p_float + (*str - '0') * div;
		str++;
	}
	return((p_float + p_int) * singe);
}
