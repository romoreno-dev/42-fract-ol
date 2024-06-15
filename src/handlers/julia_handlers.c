/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:35:28 by romoreno          #+#    #+#             */
/*   Updated: 2024/02/18 15:36:35 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	ft_set_julia(t_complex complex, t_fractal_drawer **drawer);

void	ft_change_julia_constant(t_fractal_drawer *drawer)
{
	if (drawer->julia_alternative == 0)
		drawer->constant = drawer->constant_aux;
	drawer->julia_alternative = drawer->julia_alternative + 1;
	if (drawer->julia_alternative == 12)
		drawer->julia_alternative = 1;
	if (drawer->julia_alternative == 1)
		ft_set_julia((t_complex){-0.4, 0.6}, &drawer);
	else if (drawer->julia_alternative == 2)
		ft_set_julia((t_complex){0.285, 0}, &drawer);
	else if (drawer->julia_alternative == 3)
		ft_set_julia((t_complex){0.285, 0.01}, &drawer);
	else if (drawer->julia_alternative == 4)
		ft_set_julia((t_complex){0.45, 0.1428}, &drawer);
	else if (drawer->julia_alternative == 5)
		ft_set_julia((t_complex){-0.70176, -0.3842}, &drawer);
	else if (drawer->julia_alternative == 6)
		ft_set_julia((t_complex){-0.835, -0.2321}, &drawer);
	else if (drawer->julia_alternative == 7)
		ft_set_julia((t_complex){-0.8, -0.156}, &drawer);
	else if (drawer->julia_alternative == 8)
		ft_set_julia((t_complex){-0.7269, 0.1889}, &drawer);
	else if (drawer->julia_alternative == 9)
		ft_set_julia((t_complex){0, 0.8}, &drawer);
	else if (drawer->julia_alternative == 10)
		ft_set_julia((t_complex){0.35, 0.35}, &drawer);
}

static void	ft_set_julia(t_complex complex, t_fractal_drawer **drawer)
{
	(*drawer)->constant = complex;
}
