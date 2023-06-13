/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_m_j.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:59:29 by majrou            #+#    #+#             */
/*   Updated: 2023/06/13 04:38:18 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(int end, double x, double min, double max)
{
	return ((x * (max - min) / end + min));
}

void	ft_pixel_color(int x, int y, int color, void *info)
{
	t_mlx	*data;
	int		pixel;

	data = info;
	pixel = ((y * data->line_length) + (x * 4));
	if (data->endian == 1)
	{
		data->addr[pixel + 0] = (color >> 24);
		data->addr[pixel + 1] = (color >> 16) & 0xFF;
		data->addr[pixel + 2] = (color >> 8) & 0xFF;
		data->addr[pixel + 3] = (color) & 0xFF;
	}
	else if (data->endian == 0)
	{
		data->addr[pixel + 0] = (color) & 0xFF;
		data->addr[pixel + 1] = (color >> 8) & 0xFF;
		data->addr[pixel + 2] = (color >> 16) & 0xFF;
		data->addr[pixel + 3] = (color >> 24);
	}
}

int	mand_main(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 800, 800, "majrou");
	mlx->img = mlx_new_image(mlx->mlx, 800, 800);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bit_per_pixel,
			&mlx->line_length, &mlx->endian);
	mlx->max_iteration = 90;
	mlx->scale_factor = 1;
	mlx->color2 = 0xFFFFFF;
	mlx->color3 = 0x2F4F4F;
	mandlbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 2, 1L << 0, key_hook_m, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, ft_zoom_m, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

int	julia_main(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->init = mlx_new_image(mlx->mlx, 800, 800);
	mlx->win = mlx_new_window(mlx->mlx, 800, 800, "Julia");
	mlx->img = mlx_new_image(mlx->mlx, 800, 800);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bit_per_pixel,
			&mlx->line_length, &mlx->endian);
	mlx->max_iteration = 50;
	mlx->scale_factor = 1;
	mlx->color = 0x0000FF;
	mlx->color3 = 0x0b5394;
	julia(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 2, 1L << 0, key_hook_j, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, ft_zoom_j, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
