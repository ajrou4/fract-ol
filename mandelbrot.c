/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:44:09 by majrou            #+#    #+#             */
/*   Updated: 2023/06/09 22:44:10 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandlbrot(t_mlx *mlx)
{
	mlx->x = 0;
	while (mlx->x < 800)
	{
		mlx->y = 0;
		while (mlx->y < 800)
		{
			mlx->z_re = 0;
			mlx->z_img = 0;
			mlx->c_re = (mlx->x - 400) / (mlx->scale_factor * 400);
			mlx->c_img = (mlx->y - 400) / (mlx->scale_factor * 400);
			mlx->i = 0;
			while (mlx->z_re * mlx->z_re + mlx->z_img * mlx->z_img < 4 && mlx->i < mlx->max_iteration)
			{
				mlx->tmp = mlx->z_re;
				mlx->z_re = mlx->z_re * mlx->z_re - mlx->z_img * mlx->z_img + mlx->c_re;
				mlx->z_img = 2 * mlx->z_img * mlx->tmp + mlx->c_img;
				mlx->i++;
			}
			if (mlx->i == mlx->max_iteration)
				mlx->color = 0x000000;
			else
				mlx->color = mlx->color2 * mlx->i + mlx->color3;
			mlx->addr[mlx->y * mlx->line_length + mlx->x * mlx->bit_per_pixel / 8] = mlx->color;
			mlx->addr[mlx->y * mlx->line_length + mlx->x * mlx->bit_per_pixel / 8 + 1] = mlx->color / 256;
			mlx->addr[mlx->y * mlx->line_length + mlx->x * mlx->bit_per_pixel / 8 + 2] = mlx->color / 65536;
			mlx->y++;
		}
		mlx->x++;
	}
}

int	ft_zoom(int button, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	if (button == 4)
	{
		mlx->max_iteration += 10;
		mlx->scale_factor *= 0.9;
	}
	if (button == 5)
	{
		mlx->max_iteration -= 10;
		mlx->scale_factor *= 1.1;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	mandlbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		mlx->max_iteration += 10;
		mlx->scale_factor *= 0.9;
	}
	if (keycode == 78)
	{
		mlx->max_iteration -= 10;
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



int		main(void)
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 800, 800, "mlx 42");
	mlx->img = mlx_new_image(mlx->mlx, 800, 800);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bit_per_pixel, &mlx->line_length, &mlx->endian);
	mlx->max_iteration = 100;
	mlx->scale_factor = 1;
	mlx->color2 = 0xFFFFFF;
	mlx->color3 = 0x2F4F4F;
	mandlbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 2, 1L<<0, key_hook, mlx);
	mlx_hook(mlx->win, 4, 1L<<2, ft_zoom, mlx);
	mlx_loop(mlx->mlx);
}
