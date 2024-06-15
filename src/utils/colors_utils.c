/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:39:12 by romoreno          #+#    #+#             */
/*   Updated: 2024/02/18 16:16:21 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	ft_pixel(int r, int g, int b, int a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	ft_set_color_pixel(int x, int y, t_fractal_image *image, int color)
{
	int	offset;

	offset = (y * image->line_length) + (x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->pixels_ptr + offset) = color;
}

int	compute_color_mandel(int i, int iteration_limit, int color_opt)
{
	double	t;

	t = 1.0 * i / (iteration_limit);
	if (color_opt == 1)
	{
		return (ft_pixel(255 * 9 * (1 - t) * t * t * t, \
		15 * 255 * (1 - t) * (1 - t) * t * t, \
		8.5 * 255 * (1 - t) * (1 - t) * (1 - t) * t, \
		0));
	}
	else if (color_opt == 2)
	{
		return (ft_pixel(255 * 15 * (1 - t) * t * t * t, \
		9 * 255 * (1 - t) * (1 - t) * t * t, \
		8.5 * 255 * (1 - t) * (1 - t) * (1 - t) * t, \
		0));
	}
	else if (color_opt == 3)
	{
		return (ft_pixel(255 * 10 * (1 - t) * t * t * t, \
		255 * 20 * (1 - t) * (1 - t) * t * t, \
		255 * 5.5 * (1 - t) * (1 - t) * (1 - t) * t, \
		0));
	}
	return (0);
}
