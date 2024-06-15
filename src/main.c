/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:52:53 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/18 23:52:53 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal_drawer	drawer;

	if ((argc == 2 && (!ft_strcmp(argv[1], MANDELBROT)
				|| !ft_strcmp(argv[1], BURNING)))
		|| (argc == 4 && !ft_strcmp(argv[1], JULIA)))
	{
		drawer.type = argv[1];
		if (argc == 4 && !ft_strcmp(argv[1], JULIA))
		{
			if (!ft_are_all_numbers(&argv[2]))
				ft_error_with_instructions();
			else
			{
				drawer.constant_aux = (t_complex){ft_ascii_to_double(argv[2]), \
				ft_ascii_to_double(argv[3])};
			}
		}
		ft_init(&drawer);
		ft_render(&drawer);
		mlx_loop(drawer.mlx_connection);
	}
	else
		ft_error_with_instructions();
}
