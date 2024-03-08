/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:51:02 by hidriouc          #+#    #+#             */
/*   Updated: 2024/03/08 13:09:28 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_handelinput(char *str)
{
	int	i;
	int	not;

	i = 0;
	not = 0;
	if(str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (not == 0 && str[i] == '.')
			not = 1;
		else if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr("Error on input v1 v1 for julia \n");
			exit(EXIT_FAILURE);
		}
		i++;
		if (str[i] == '\0')
			return;
	}
	if (str[i] == '\0')
	{
		ft_putstr("Error on input v1 v1 for julia \n");
		exit(EXIT_SUCCESS);
	}
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	mlx_error(t_fract	*fractol, char *s)
{
	ft_putstr(s);
	free(fractol->mlx_connectoin);
	exit(EXIT_SUCCESS);
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
