/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controllers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:40:28 by romoreno          #+#    #+#             */
/*   Updated: 2024/02/18 18:38:42 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	ft_init_listeners(t_fractal_drawer *drawer);

void	ft_init_data(t_fractal_drawer *drawer)
{
	drawer->iteration_limit = ITERATION_LIMIT;
	drawer->b.x_min = -MAGIC_NUMBER;
	drawer->b.y_min = -MAGIC_NUMBER;
	drawer->b.x_max = MAGIC_NUMBER;
	drawer->b.y_max = MAGIC_NUMBER;
	drawer->color_option = 1;
	drawer->julia_alternative = 0;
	drawer->constant = drawer->constant_aux;
}

void	ft_init(t_fractal_drawer *d)
{
	d->mlx_connection = mlx_init();
	if (!d->mlx_connection)
		ft_error();
	d->mlx_window = mlx_new_window(d->mlx_connection, WDH, HGT, d->type);
	if (!d->mlx_window)
	{
		free(d->mlx_connection);
		ft_error();
	}
	d->fractal_image.img_ptr = mlx_new_image(d->mlx_connection, WDH, HGT);
	if (!d->fractal_image.img_ptr)
	{
		mlx_destroy_window(d->mlx_connection, d->mlx_window);
		free(d->mlx_connection);
		ft_error();
	}
	d->fractal_image.pixels_ptr = mlx_get_data_addr(d->fractal_image.img_ptr,
			&d->fractal_image.bits_per_pixel,
			&d->fractal_image.line_length,
			&d->fractal_image.endian);
	ft_init_listeners(d);
	ft_init_data(d);
	ft_print_iterations(d);
}

static void	ft_init_listeners(t_fractal_drawer *drawer)
{
	mlx_key_hook(drawer->mlx_window, ft_key_handler, drawer);
	mlx_mouse_hook(drawer->mlx_window, ft_mouse_handler, drawer);
	mlx_hook(drawer->mlx_window, 17, 0L, ft_close_handler, drawer);
}
