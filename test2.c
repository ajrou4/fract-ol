/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:34:43 by majrou            #+#    #+#             */
/*   Updated: 2023/06/04 06:09:23 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot_set(t_mlx *mlx) 
{
  mlx->max_iteration = 50;
  mlx->z_re = 0.0;
  mlx->z_img = 0.0;
  mlx->c_re = 0.0;
  mlx->c_img = 0.0;
  mlx->x = 0;
  mlx->sqrt_modulus;
  mlx->scale_factor;
  mlx->color;
  while (mlx->x < WIDTH) 
  {
    mlx->y = 0;
    while (mlx->y < HEIGHT) 
    {
      set_complex_numbers(&mlx->z_re, &mlx->z_img, mlx->x, mlx->y, mlx->scale_factor);
      mlx->i = 0;
      while (mlx->sqrt_modulus < 4.0 && mlx->i < mlx->max_iteration) 
      {
        mlx->z_re = iterate_mandelbrot_equation(mlx->z_re, mlx->z_img, mlx->c_re, mlx->c_img);
        mlx->sqrt_modulus = get_modulus(mlx->z_re, mlx->z_img);
        mlx->i++;
      }
      mlx->color = get_color(mlx->i);
      draw_pixel(mlx->mlx, mlx->x, mlx->y, mlx->color);
      mlx->y++;
    }
    mlx->x++;
  }
  mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
  mlx_loop(mlx->init);
}

void set_complex_numbers(double *z_re, double *z_img, int x, int y, double scale_factor) 
{
    t_mlx *mlx;
    mlx->z_re = (mlx->x - WIDTH / 2.0) * scale_factor;
    mlx->z_img = (mlx->y - HEIGHT / 2.0) * scale_factor;
}

double iterate_mandelbrot_equation(double z_re, double z_img, double c_re, double c_img) 
{
  double tmp = z_re;
  z_re = z_re * z_re - z_img * z_img + c_re;
  z_img = 2 * z_img * tmp + c_img;
  return z_re;
}

double get_modulus(double z_re, double z_img) 
{
  return z_re * z_re + z_img * z_img;
}

void draw_pixel(t_mlx *mlx) 
{
  mlx_pixel_put(mlx->img, mlx->x, mlx->y, mlx->color);
}
