/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:17:34 by majrou            #+#    #+#             */
/*   Updated: 2023/06/04 00:18:39 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void    mandelbrot(t_mlx *mlx)
{
    
    int max_iteration = 50;
  double z_re = 0;
  double z_img = 0;
  double c_re = 0;
  double c_img = 0;
  int i = 0;
  int y = 0, x = 0;
  double sqrt_modulus;
  double scale_factor;
  double height = 1000;
  double width = 1000;
  int color;


  scale_factor = 4.0 / width;

  while (x < width) 
  {
    y = 0;
    while (y < height) {

      z_re = 0;
      z_img = 0;
      c_re = (x - width / 2.0) * scale_factor;
      c_img = (y - height / 2.0) * scale_factor;

      while (sqrt_modulus < 4 && i < max_iteration) 
      {
        z_re = z_re * z_re - z_img * z_img + c_re;
        z_img = 2 * z_re * z_img + c_img;
        sqrt_modulus = z_re * z_re + z_img * z_img;
        i++;
      }


      color = get_color(i);


      draw_pixel(mlx, x, y, color);

      y++;
    }
       x++;
  }
    mlx_put_image_to_window(mlx->init, mlx->window, mlx->img, 0, 0);
}