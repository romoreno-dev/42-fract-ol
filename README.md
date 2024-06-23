
# 1. Get started

- Clonar el repositorio
- Se dispone de un Makefile con las reglas `all`, `fractol`, `clean`, `fclean`, `re`
- Ejecutando el comando `make` se compila el binario `fractol` que contiene el programa

Se ejecuta `fractol`,....



# 2. Contenido del repositorio

- El repositorio contiene **fract-ol**, séptimo proyecto del Cursus de 42, correspondiente al segundo círculo (Rank 02).
- El proyecto sigue la [Norminette](https://github.com/42School/norminette), norma de estilo oficial del Campus.
- Utiliza la librería MiniLibX (MLX), desarrollada en C por Olivier Crouzet para actuar sobre X11, un sistema de ventanas para imágenes en mapa de bits utilizado en sistemas Unix. 

##  fact-ol 42 Project (Rank 02)
Score: 125/100

### Explicación del proyecto

#### (BONUS)

Simulador didáctico de fractales en el plano complejo

------------------------------------------------------------
**FRACTALES SIMULADOS:**
- FRACTAL DE MANDELBROT: Introduzca "./fractol mandelbrot"
- FRACTAL DE BURNING SHIP: Introduzca "./fractol burning"
- FRACTAL DE JULIA: Introduzca "./fractol julia [Re] [Im]"
------------------------------------------------------------


------------------------------------------------------------
**CONTROLES DE LA SIMULACIÓN (Inicialmente configurados para MacOS):**   

Teclas Up-Left-Right-Down W-A-D-S: Recorre el fractal  
Scroll del ratón: Zoom in y Zoom out  
Tecla +: Aumentar el número de iteraciones de comprobación (El rendimiento puede verse afectado según el hardware)  
Tecla -: Disminuir el número de iteraciones de comprobación  
Tecla R: Reinicia al fractal a las condiciones iniciales  
Tecla 1: Cambia la gama de colores  
Tecla J: (Solo en fractal de Julia): Fractales artísticos  
Tecla ESC: Finaliza la simulación del fractal  
------------------------------------------------------------


------------------------------------------------------------
**CONCEPTOS:**
- FRACTAL:Figura formada por patrones que se repiten.
  Usos: Compresión multimedia, modelado, criptografía, arte.

- NÚMERO COMPLEJO: Compuesto por dos partes, parte real (Re) y parte imaginaria (iIm).
  Representado como (z = x + yi)
  Ejemplos: 3 + 0i ; 0 - 3i ; -0.4 + 0.6i

- PLANO COMPLEJO: Visualizar los números complejos  en forma de puntos cartesianos Z(x,y)

- FRACTALES DERIVADOS DE MANDELBROT: Partiendo de z0 y c, se aplican series similares a  z(n+1) = z(n)^2 + c hasta la condición de divergencia.
  La serie se aplica en cada punto y, según la iteración  a la que diverge, se le asigna un color
  Si el punto no diverge en las iteraciones probadas, se le asigna el color elegido como neutro
  Se dirá entonces que ese punto pertenece al conjunto.
  A mayor número de iteraciones, mayor nitidez del fractal
------------------------------------------------------------
