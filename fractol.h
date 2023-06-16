/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 03:17:41 by majrou            #+#    #+#             */
/*   Updated: 2023/06/16 12:54:02 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <limits.h>

typedef struct s_mlx
{
	int		w;
	int		h;
	void	*mlx;
	void	*init;
	void	*win;
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	double	z_re ;
	double	z_img ;
	double	c_re ;
	double	c_img;
	double	tmp;
	int		x;
	int		y;
	int		i;
	int		max_iteration;
	double	sqrt_modulus;
	double	scale_factor;
	int		color;
	int		color2;
	int		color3;
}	t_mlx;

long	ft_latoi(char *str);
void	error(int a);
int		mand_main(t_mlx	*mlx);
int		julia_main(t_mlx *mlx);
int		ft_isdigit(int c);
double	ft_atof(char *str, double res);
int		key_hook_j(int keycode, t_mlx *mlx);
int		ft_zoom_j(int button, int x, int y, t_mlx *mlx);
int		key_hook_m(int keycode, t_mlx *mlx);
int		ft_zoom_m(int button, int x, int y, t_mlx *mlx);
void	mandlbrot(t_mlx *mlx);
void	julia(t_mlx *mlx);
double	ft_map(int end, double x, double min, double max);
void	ft_pixel_color(int x, int y, int color, void *info);
#endif
