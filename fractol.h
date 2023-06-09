#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
#include <stdlib.h>
#include <stdio.h>
# include "mlx/mlx.h"
# include <limits.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct s_mlx
{
	void	*mlx;
	void *init;
	void *win;
	void *img;
	char *addr;
	int bit_per_pixel;
	int line_length;
	int endian;
	double z_re ;
	double z_img ;
	double c_re ;
	double c_img;
	double tmp;
	int		x;
	int		y;
	int		i;
	int max_iteration;
	double sqrt_modulus;
	double scale_factor;
	int color;
	int color2;
	int color3;
} t_mlx;

#endif
