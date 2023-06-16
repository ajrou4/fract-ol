/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:47:34 by majrou            #+#    #+#             */
/*   Updated: 2023/06/16 13:22:49 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_help(t_mlx *mlx)
{
	mlx->z_re = ft_map(800, mlx->x, -2, 2) * mlx->scale_factor;
	mlx->z_img = ft_map(800, mlx->y, -2, 2) * mlx->scale_factor;
	mlx->i = 0;
}

void	julia(t_mlx *mlx)
{
	mlx->x = 0;
	while (mlx->x < 800)
	{
		mlx->y = 0;
		while (mlx->y < 800)
		{
			ft_help(mlx);
			while (mlx->z_re * mlx->z_re + mlx->z_img * mlx->z_img < 4
				&& mlx->i < mlx->max_iteration)
			{
				mlx->tmp = mlx->z_re;
				mlx->z_re = mlx->z_re * mlx->z_re - mlx->z_img * mlx->z_img
					+ mlx->c_re;
				mlx->z_img = 2 * mlx->z_img * mlx->tmp - mlx->c_img;
				mlx->i++;
			}
			if (mlx->i == mlx->max_iteration)
				ft_pixel_color(mlx->x, mlx->y, mlx->color * pow(mlx->i, 2),
					mlx);
			else
				ft_pixel_color(mlx->x, mlx->y, 0x000000, mlx);
			mlx->y++;
		}
		mlx->x++;
	}
}

int	ft_zoom_j(int button, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	if (button == 4)
		mlx->scale_factor *= 0.9;
	if (button == 5)
		mlx->scale_factor *= 1.1;
	mlx_clear_window(mlx->mlx, mlx->win);
	julia(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int	key_hook_j(int keycode, t_mlx *mlx)
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
	julia(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
