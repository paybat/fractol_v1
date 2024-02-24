/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:10:09 by hidriouc          #+#    #+#             */
/*   Updated: 2024/02/24 13:39:26 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	chang_Between(int unscaledNum, int n_min, int n_max, int min, double max)
{
	return ((n_max - n_min) * (unscaledNum - min) / (max - min) + n_min);
}
t_ncomplix	sum(t_ncomplix	c1, t_ncomplix	c2)
{
	t_ncomplix	r;
	
	r.x = c1.x + c2.x;
	r.y = c1.y + c2.y;
	return (r);
}
t_ncomplix	power_tow(t_ncomplix z)
{
	t_ncomplix	r;

	r.x = (z.x * z.x) - (z.y * z.y);
	r.y = 2 * z.x * z.y;
	return (r);
}
