// #include "fractol.h"

// int	ptr(int button,int x, int y)
// {
// 	button = 1;
// 	t_mlx lx;
// 	mlx_pixel_put(lx.win ,lx.mlx , x, y, 0xFFFFFF);
// 	return (0);
// }

// int	main(void)
// {
// 	t_mlx lx;
// 	void	*image;

// 	lx.mlx = mlx_init();
// 	lx.win = mlx_new_window(lx.mlx, 800, 800, "jamaica");
// 	image = mlx_new_image(lx.mlx, 800, 800);
// 	mlx_put_image_to_window(lx.mlx, lx.win, image, 500, 500);
// 	mlx_mouse_hook(lx.win, &ptr, 0);
// 	julia(double z_re, double z_im)


// 	mlx_loop(lx.mlx);
// }

// int	drawiong(t_mlx *mlx, int w, int h, int color)
// {
// 	char	*addr;

// 	addr = mlx->addr_ptr + (h * mlx->line_lenght + w * (mlx->bit_per_pixel
// 				/ 8));
// 	*(unsigned int *)addr = color;
// 	return (0);
// }
