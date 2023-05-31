#include "fractol.h"
#include <mlx.h>

// int	ptr(int button,int x, int y)
// {
// 	button = 1;
// 	// t_mlx lx;
// 	mlx_pixel_put(lx.win ,lx.mlx , x, y, 0xFFFFFF);
// 	return (0);
// }

typedef struct f_mlx
{
	void	*mlx;
	void	*init_ptr;
	void	*window_ptr;
	char	*img_ptr;
	char	*addr_ptr;
	int		bit_per_pixel;
	int		line_lenght;
	int		endian;
	void	*image;

}t_mlx;
int	drawing(void *mlx, int w, int h, int color)
{
	char	*addr;
	char	*addr_ptr;
	int		bit_per_pixel;
	int		line_lenght;
	char	*img_ptr;

	addr = addr_ptr + (h * line_lenght + w * (bit_per_pixel / 8));
	*(unsigned int *)addr = color;
	return (0);
}



void mandelbrot(double z_re, double z_im)
{
	t_mlx *mlx;
	double c_re;
	double c_im;
	// void	*init_ptr;
	// void	*window_ptr;
	// char	*img_ptr;

	int iter = 0;
	int max_iter = 50;
	double x = 0;
	double y = 0;
	double check_modulo;

	while (x < 800)
	{
		y = 0;
		while (y < 800)
		{
			z_re = 0;
			z_im = 0;

			check_modulo = z_re * z_re + z_im * z_im;
			while (iter <= max_iter && check_modulo < 4)
			{
				double factor = 4.0 / 800;
				c_re = (x - 800/ 2.0) * factor;
				c_im = (y - 800 / 2.0) * factor;
				double tmp = z_re;
				z_re = z_re * z_re + c_re;
				z_im = 2 * tmp * z_im - z_im * z_im + c_im;
				check_modulo = z_re * z_re + z_im * z_im;
				iter++;
				if (iter < 11)
					drawing(mlx, x, y, 0xf48c06);
				else if (iter < 25)
					drawing(mlx, x, y, 0x000000);
				else
					drawing(mlx, x, y, 0xffffff);

				y++;

			}

		x++;
	}
}
	mlx_put_image_to_window(mlx->init_ptr, mlx->window_ptr,  mlx->img_ptr, 0, 0);
}

int	main(void)
{
		t_mlx	mlx;
	// void	*mlx;
	// void	*init_ptr;
	// void	*window_ptr;
	// char	*img_ptr;
	// char	*addr_ptr;
	// int		bit_per_pixel;
	// int		line_lenght;
	// int		endian;
	// void	*image;

	mlx.init_ptr = mlx_init();
	mlx.mlx = mlx_new_window(mlx.init_ptr, 800, 800, "jamaica");
	mlx.init_ptr = mlx_new_image(mlx.init_ptr, 800, 800);
	mlx_loop(mlx.mlx);
}
