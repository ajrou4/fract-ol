/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:44:09 by majrou            #+#    #+#             */
/*   Updated: 2023/06/13 01:15:03 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_mlx *mlx)
{
	mlx->z_re = 0;
	mlx->z_img = 0;
	mlx->c_re = 2 * (mlx->x - 400) / (mlx->scale_factor * 400);
	mlx->c_img = 2 * (mlx->y - 400) / (mlx->scale_factor * 400);
	mlx->i = 0;
}

void	itertion_man(t_mlx *mlx)
{
	mlx->tmp = mlx->z_re;
	mlx->z_re = mlx->z_re * mlx->z_re - mlx->z_img * mlx->z_img + mlx->c_re;
	mlx->z_img = 2 * mlx->z_img * mlx->tmp + mlx->c_img;
	mlx->i++;
}

void	mandlbrot(t_mlx *mlx)
{
	mlx->x = 0;
	while (mlx->x < 800)
	{
		mlx->y = 0;
		while (mlx->y < 800)
		{
			init_mandelbrot(mlx);
			while (mlx->z_re * mlx->z_re + mlx->z_img * mlx->z_img < 4
				&& mlx->i < mlx->max_iteration)
				itertion_man(mlx);
			if (mlx->i == mlx->max_iteration)
				mlx->color = 0x000000;
			else
				mlx->color = mlx->color2 * mlx->i + mlx->color3;
			mlx->addr[mlx->y * mlx->line_length + mlx->x * mlx->bit_per_pixel
				/ 8] = mlx->color;
			mlx->addr[mlx->y * mlx->line_length + mlx->x * mlx->bit_per_pixel
				/ 8 + 1] = mlx->color / 256;
			mlx->addr[mlx->y * mlx->line_length + mlx->x * mlx->bit_per_pixel
				/ 8 + 2] = mlx->color / 65536;
			mlx->y++;
		}
		mlx->x++;
	}
}

int	ft_zoom_m(int button, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	if (button == 4)
		mlx->scale_factor *= 0.9;
	if (button == 5)
		mlx->scale_factor *= 1.1;
	mlx_clear_window(mlx->mlx, mlx->win);
	mandlbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int	key_hook_m(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		mlx->scale_factor *= 0.9;
	}
	if (keycode == 78)
	{
		mlx->scale_factor *= 1.1;
	}
	if (keycode == 123)
		mlx->color2 += 100;
	if (keycode == 124)
		mlx->color2 -= 100;
	if (keycode == 125)
		mlx->color3 += 100;
	if (keycode == 126)
		mlx->color3 -= 100;
	mlx_clear_window(mlx->mlx, mlx->win);
	mandlbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
