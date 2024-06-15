/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:40:40 by romoreno          #+#    #+#             */
/*   Updated: 2024/02/18 15:50:09 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	ft_print_header(void);
static void	ft_print_controls(void);
static void	ft_print_theory(void);

void	ft_print_instructions(void)
{
	ft_print_header();
	ft_print_controls();
	ft_print_theory();
}

void	ft_print_iterations(t_fractal_drawer *drawer)
{
	ft_printf("Pertenece al conjunto si no diverge a las %d iteraciones\n", \
	drawer->iteration_limit);
}

static void	ft_print_header(void)
{
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("███████╗██████╗  █████╗  ██████╗████████╗ ██████╗ ██╗\n");
	ft_printf("██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██║\n");
	ft_printf("█████╗  ██████╔╝███████║██║        ██║   ██║   ██║██║\n");
	ft_printf("██╔══╝  ██╔══██╗██╔══██║██║        ██║   ██║   ██║██║\n");
	ft_printf("██║     ██║  ██║██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗\n");
	ft_printf("╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝\n");
	ft_printf("\n");
	ft_printf("Simulador didáctico de fractales en el plano complejo\n");
	ft_printf("\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("FRACTALES SIMULADOS:\n");
	ft_printf("- FRACTAL DE MANDELBROT: Introduzca \"./fractol mandelbrot\"\n");
	ft_printf("- FRACTAL DE BURNING SHIP: Introduzca \"./fractol burning\"\n");
	ft_printf("- FRACTAL DE JULIA: Introduzca \"./fractol julia [Re] [Im]\"\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("\n");
}

static void	ft_print_controls(void)
{
	ft_printf("------------------------------------------------------------\n");
	ft_printf("CONTROLES DE LA SIMULACIÓN:\n");
	ft_printf("Teclas Up-Left-Right-Down W-A-D-S: Recorre el fractal\n");
	ft_printf("Scroll del ratón: Zoom in y Zoom out\n");
	ft_printf("Tecla +: Aumentar el número de iteraciones de comprobación");
	ft_printf(" (El rendimiento puede verse afectado según el hardware)\n");
	ft_printf("Tecla -: Disminuir el número de iteraciones de comprobación\n");
	ft_printf("Tecla R: Reinicia al fractal a las condiciones iniciales\n");
	ft_printf("Tecla 1: Cambia la gama de colores\n");
	ft_printf("Tecla J: (Solo en fractal de Julia): Fractales artísticos\n");
	ft_printf("Tecla ESC: Finaliza la simulación del fractal\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("\n");
}

static void	ft_print_theory(void)
{
	ft_printf("------------------------------------------------------------\n");
	ft_printf("CONCEPTOS:\n");
	ft_printf("- FRACTAL:Figura formada por patrones que se repiten.\n");
	ft_printf("  Usos: Compresión multimedia, modelado, criptografía, arte.\n");
	ft_printf("\n");
	ft_printf("- NÚMERO COMPLEJO: Compuesto por dos partes,");
	ft_printf(" parte real (Re) y parte imaginaria (iIm). \n");
	ft_printf("   Representado como (z = x + yi)\n");
	ft_printf("   Ejemplos: 3 + 0i ; 0 - 3i ; -0.4 + 0.6i\n");
	ft_printf("\n");
	ft_printf("- PLANO COMPLEJO: Visualizar los números complejos ");
	ft_printf(" en forma de puntos cartesianos Z(x,y)\n");
	ft_printf("\n");
	ft_printf("- FRACTALES DERIVADOS DE MANDELBROT: Partiendo de z0 y c, ");
	ft_printf("se aplican series similares a ");
	ft_printf(" z(n+1) = z(n)^2 + c hasta la condición de divergencia.\n");
	ft_printf("   La serie se aplica en cada punto y, según la iteración ");
	ft_printf(" a la que diverge, se le asigna un color\n");
	ft_printf("   Si el punto no diverge en las iteraciones probadas, ");
	ft_printf("se le asigna el color elegido como neutro\n");
	ft_printf("   Se dirá entonces que ese punto pertenece al conjunto.\n");
	ft_printf("   A mayor número de iteraciones, mayor nitidez del fractal\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("\n");
}
