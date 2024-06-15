/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:40:07 by romoreno          #+#    #+#             */
/*   Updated: 2024/02/18 16:03:27 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	ft_directions_key_handler(int keysym, t_fractal_drawer *drawer);
static void	ft_iterations_key_handler(int keysym, t_fractal_drawer *drawer);
static void	ft_another_keys_handler(int keysym, t_fractal_drawer *drawer);

int	ft_mouse_handler(int button, int x, int y, t_fractal_drawer *d)
{
	double	dff;
	double	diff_y;

	dff = d->b.x_max - d->b.x_min;
	diff_y = d->b.y_max - d->b.y_min;
	if (button == SCROLL_UP)
	{
		d->b.x_min = d->b.x_min + x * (dff / WDH) * (1 - OUTCONST);
		d->b.x_max = d->b.x_min + OUTCONST * (dff);
		d->b.y_max = d->b.y_max - ((HGT - y) * (diff_y / HGT) * (1 - OUTCONST));
		d->b.y_min = d->b.y_max - OUTCONST * (diff_y);
	}
	else if (button == SCROLL_DOWN)
	{
		d->b.x_min = d->b.x_min + x * (dff / WDH) * (1 - INCONST);
		d->b.x_max = d->b.x_min + INCONST * (dff);
		d->b.y_max = d->b.y_max - ((HGT - y) * (diff_y / HGT) * (1 - INCONST));
		d->b.y_min = d->b.y_max - INCONST * (diff_y);
	}
	ft_render(d);
	return (0);
}

int	ft_key_handler(int keysym, t_fractal_drawer *drawer)
{
	if (keysym == LEFT || keysym == A || keysym == RIGHT || keysym == D
		|| keysym == UP || keysym == W || keysym == DOWN || keysym == S)
	{
		ft_directions_key_handler(keysym, drawer);
	}
	else if (keysym == ADD || keysym == SUBTRACT)
	{
		ft_iterations_key_handler(keysym, drawer);
	}
	else if (keysym == ESC || keysym == R || keysym == C || keysym == J)
	{
		ft_another_keys_handler(keysym, drawer);
	}
	ft_render(drawer);
	return (0);
}

static void	ft_directions_key_handler(int keysym, t_fractal_drawer *drawer)
{
	double	dist;

	dist = drawer->b.x_max - drawer->b.x_min;
	if (keysym == LEFT || keysym == A)
	{
		drawer->b.x_min = drawer->b.x_min - SHIFT * (dist);
		drawer->b.x_max = drawer->b.x_max - SHIFT * (dist);
	}
	else if (keysym == RIGHT || keysym == D)
	{
		drawer->b.x_min = drawer->b.x_min + SHIFT * (dist);
		drawer->b.x_max = drawer->b.x_max + SHIFT * (dist);
	}
	else if (keysym == UP || keysym == W)
	{
		drawer->b.y_min = drawer->b.y_min - SHIFT * (dist);
		drawer->b.y_max = drawer->b.y_max - SHIFT * (dist);
	}
	else if (keysym == DOWN || keysym == S)
	{
		drawer->b.y_min = drawer->b.y_min + SHIFT * (dist);
		drawer->b.y_max = drawer->b.y_max + SHIFT * (dist);
	}
}

static void	ft_iterations_key_handler(int keysym, t_fractal_drawer *drawer)
{
	if (keysym == ADD)
	{
		if (drawer->iteration_limit >= 1 && drawer->iteration_limit < 60)
		{
			drawer->iteration_limit++;
			ft_print_iterations(drawer);
		}
		else if (drawer->iteration_limit < 500)
		{
			drawer->iteration_limit += 20;
			ft_print_iterations(drawer);
		}
	}
	else if (keysym == SUBTRACT)
	{
		if (drawer->iteration_limit > 60)
			drawer->iteration_limit -= 20;
		else if (drawer->iteration_limit > 1 && drawer->iteration_limit <= 60)
			drawer->iteration_limit--;
		ft_print_iterations(drawer);
	}
}

static void	ft_another_keys_handler(int keysym, t_fractal_drawer *drawer)
{
	if (keysym == R)
		ft_init_data(drawer);
	else if (keysym == C)
	{
		if (drawer->color_option < 3)
		{
			drawer->color_option = drawer->color_option + 1;
		}
		else
		{
			drawer->color_option = 1;
		}
	}
	else if (keysym == J)
	{
		if (!ft_strcmp(drawer->type, JULIA))
		{
			ft_change_julia_constant(drawer);
		}
	}
	else if (keysym == ESC)
		ft_close_handler(drawer);
}
