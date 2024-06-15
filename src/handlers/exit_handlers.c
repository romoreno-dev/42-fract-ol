/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:40:17 by romoreno          #+#    #+#             */
/*   Updated: 2024/02/18 19:22:10 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/*
 * Ends the execution.
 * At the end could be used "free(drawer->mlx_connection)"
*/
int	ft_close_handler(t_fractal_drawer *drawer)
{
	mlx_destroy_image(drawer->mlx_connection, drawer->fractal_image.img_ptr);
	mlx_destroy_window(drawer->mlx_connection, drawer->mlx_window);
	exit(EXIT_SUCCESS);
}

void	ft_error(void)
{
	perror(ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}

int	ft_error_with_instructions(void)
{
	ft_print_instructions();
	exit(EXIT_FAILURE);
}
