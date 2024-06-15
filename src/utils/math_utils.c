/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:44:01 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/30 18:44:01 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

t_complex	ft_square_complex(t_complex z)
{
	return ((t_complex){(z.re * z.re) - (z.im * z.im), (2 * z.re * z.im)});
}

t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	return ((t_complex){z1.re + z2.re, z1.im + z2.im});
}

double	ft_square_module(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}

double	ft_abs(double number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

int	ft_are_all_numbers(char **numbers)
{
	int	i;
	int	j;
	int	point;
	int	signum;

	i = -1;
	while (numbers[++i])
	{
		j = -1;
		point = 0;
		signum = 0;
		if (numbers[i][++j] == '+' || numbers[i][j] == '-')
			signum = 1;
		if (numbers[i][j] == '+' || numbers[i][j] == '-')
			j++;
		while (numbers[i][++j])
		{
			if ((!ft_isdigit(numbers[i][j]) && numbers[i][j] != '.')
			|| (numbers[i][j] == '.' && (point || !j || (j == 1 && signum))))
				return (0);
			else if (numbers[i][j] == '.')
				point = 1;
		}
	}
	return (1);
}
