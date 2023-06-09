/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:34:43 by majrou            #+#    #+#             */
/*   Updated: 2023/06/09 01:09:23 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <math.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <mlx.h>

// typedef struct s_mlx
// {
// 	void *mlx;
// 	void *win;
// 	void *img;
// 	char *addr;
// 	int bit_per_pixel;
// 	int line_length;
// 	int endian;
// 	double z_re;
// 	double z_img;
// 	double c_re;
// 	double c_img;
// 	double tmp;
// 	int x;
// 	int y;
// 	int i;
// 	int max_iteration;
// 	double sqrt_modulus;
// 	double scale_factor;
// 	int color;
// 	int color2;
// 	int color3;
// } t_mlx;
#include "fractol.h"

int draw_fractal(t_mlx *mlx, int width, int height, int color)
{
	char *addr = mlx->addr + (height * mlx->line_length + width * (mlx->bit_per_pixel / 8));
	*(unsigned int *)addr = color;
	return (0);
}

void cloer_fractal(t_mlx *mlx)
{
	mlx->color = mlx->i % 16 * 0x000000 + mlx->i % 16 * 0xFFFFFF;
	mlx->color2 = mlx->i % 16 * 0xF90000 + mlx->i % 16 * 0xF2D027;
	mlx->color3 = mlx->i % 16 * 0x0F1011 + mlx->i % 16 * 0xE9E9E9 + mlx->i % 16 * 0x2D3030;
	if (mlx->i < 17)
		draw_fractal(mlx, mlx->x, mlx->y, mlx->color);
	else if (mlx->i < 50)
		draw_fractal(mlx, mlx->x, mlx->y, mlx->color2);
	else
		draw_fractal(mlx, mlx->x, mlx->y, 0x000000);
}

void mandelbrot_set(t_mlx *mlx)
{
	int max_iteration = 50;
	double z_re = 0;
	double z_img = 0;
	double c_re = 0;
	double c_img = 0;
	int y = 0, x = 0;
	double sqrt_modulus;
	double scale_factor;
	double height = 1000;
	double width = 1000;

	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			z_re = 0;
			z_img = 0;
			scale_factor = 4.0 / width;
			c_re = (x - width / 2.0) * scale_factor;
			c_img = (y - height / 2.0) * scale_factor;
			mlx->i = 0;
			sqrt_modulus = z_re * z_re + z_img * z_img;
			while (sqrt_modulus < 4 && mlx->i < max_iteration)
			{
				double tmp = z_re;
				z_re = z_re * z_re - z_img * z_img + c_re;
				z_img = 2 * z_img * tmp + c_img;
				sqrt_modulus = z_re * z_re + z_img * z_img;
				mlx->i++;
			}
			cloer_fractal(mlx);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
}

int main()
{
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "ajrou");
	mlx.img = mlx_new_image(mlx.mlx, 1000, 1000);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bit_per_pixel, &mlx.line_length, &mlx.endian);

	mandelbrot_set(&mlx);

	mlx_loop(mlx.mlx);

	return 0;
}

