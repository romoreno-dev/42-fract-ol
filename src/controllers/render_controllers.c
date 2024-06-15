/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_controllers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:40:44 by romoreno          #+#    #+#             */
/*   Updated: 2024/02/18 15:38:20 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	ft_workout_pixel(int x, int y, t_fractal_drawer *drawer);
static void	ft_init_conditions(int x, int y, t_fractal_drawer *d, t_couple *pr);
static void	ft_adapt_complex_to_burning(t_complex *z);

void	ft_render(t_fractal_drawer *drawer)
{
	int	x;
	int	y;

	x = 0;
	while (x < HGT)
	{
		y = 0;
		while (y < WDH)
		{
			ft_workout_pixel(x, y, drawer);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(drawer->mlx_connection, drawer->mlx_window,
		drawer->fractal_image.img_ptr, 0, 0);
}

static void	ft_workout_pixel(int x, int y, t_fractal_drawer *drawer)
{
	t_couple	complex;
	int			iter;
	int			color;

	ft_init_conditions(x, y, drawer, &complex);
	iter = 1;
	while (iter < drawer->iteration_limit)
	{
		if (!ft_strcmp(drawer->type, BURNING))
			ft_adapt_complex_to_burning(&complex.z);
		complex.z = ft_sum_complex(ft_square_complex(complex.z), complex.c);
		if (ft_square_module(complex.z) > SCAPE_POINT)
		{
			color = compute_color_mandel(iter, drawer->iteration_limit,
					drawer->color_option);
			ft_set_color_pixel(x, y, &drawer->fractal_image, color);
			return ;
		}
		iter++;
	}
	ft_set_color_pixel(x, y, &drawer->fractal_image, BLACK);
}

static void	ft_init_conditions(int x, int y, t_fractal_drawer *d, t_couple *pr)
{
	t_borders			b;

	b = d->b;
	if (!ft_strcmp(d->type, MANDELBROT) || !ft_strcmp(d->type, BURNING))
	{
		pr->z.re = 0;
		pr->z.im = 0;
		pr->c.re = b.x_min + x * ((b.x_max - b.x_min) / (WDH));
		pr->c.im = b.y_min + y * ((b.y_max - b.y_min) / (HGT));
	}
	else if (!ft_strcmp(d->type, JULIA))
	{
		pr->z.re = b.x_min + x * ((b.x_max - b.x_min) / (WDH));
		pr->z.im = b.y_min + y * ((b.y_max - b.y_min) / (HGT));
		pr->c.re = d->constant.re;
		pr->c.im = d->constant.im;
	}
}

static void	ft_adapt_complex_to_burning(t_complex *z)
{
	z->re = ft_abs(z->re);
	z->im = ft_abs(z->im);
}
