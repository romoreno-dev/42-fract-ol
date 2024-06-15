/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:42:28 by romoreno          #+#    #+#             */
/*   Updated: 2024/01/21 15:42:28 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/include/libft.h"
# include "mlx.h"
# include <stdio.h>

# define ITERATION_LIMIT 35
# define WDH 800
# define HGT 800

# define ERROR_MESSAGE "Error al renderizar el fractal"

# define MANDELBROT "mandelbrot\0"
# define JULIA "julia\0"
# define BURNING "burning\0"

# define SCAPE_POINT 4.0
# define MAGIC_NUMBER 2

# define OUTCONST 0.9
# define INCONST 1.1
# define SHIFT 0.2

# define BLACK 0x000000

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define A 0
# define D 2
# define W 13
# define S 1
# define J 38
# define C 8
# define SUBTRACT 78
# define ADD 69
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal_image
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fractal_image;

typedef struct s_borders
{
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
}	t_borders;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_couple_complex
{
	t_complex	z;
	t_complex	c;
}	t_couple;

typedef struct s_fractal_drawer
{
	void			*mlx_connection;
	void			*mlx_window;
	t_fractal_image	fractal_image;
	char			*type;
	int				iteration_limit;
	t_borders		b;
	int				color_option;
	t_complex		constant;
	int				julia_alternative;
	t_complex		constant_aux;
}	t_fractal_drawer;

int			ft_pixel(int r, int g, int b, int a);
void		ft_set_color_pixel(int x, int y, t_fractal_image *img, int color);
int			compute_color_mandel(int i, int iteration_limit, int color_opt);

int			ft_mouse_handler(int button, int x, int y, t_fractal_drawer *d);
int			ft_key_handler(int keysym, t_fractal_drawer *drawer);

int			ft_close_handler(t_fractal_drawer *drawer);
void		ft_error(void);
int			ft_error_with_instructions(void);

void		ft_init_data(t_fractal_drawer *drawer);
void		ft_init(t_fractal_drawer *d);
void		ft_change_julia_constant(t_fractal_drawer *drawer);

t_complex	ft_square_complex(t_complex z);
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
double		ft_square_module(t_complex z);
double		ft_abs(double number);
int			ft_are_all_numbers(char **numbers);

void		ft_print_instructions(void);
void		ft_print_iterations(t_fractal_drawer *drawer);

void		ft_render(t_fractal_drawer *drawer);

int			ft_strcmp(char *s1, char *s2);
double		ft_ascii_to_double(char *s);
#endif
