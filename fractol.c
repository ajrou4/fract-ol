#include "fractol.h"

int	ptr(int button,int x, int y)
{
	button = 1;
	t_mlx mlx;
	mlx_pixel_put(mlx.win ,mlx.mlx , x, y, 0xFFFFFF);
	return (0);
}

// int	drawiong(t_mlx *mlx, int w, int h, int color)
// {
// 	char	*addr;

// 	addr = mlx->addr_ptr + (h * mlx->line_lenght + w * (mlx->bit_per_pixel
// 				/ 8));
// 	*(unsigned int *)addr = color;
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_mlx mlx;
	void	*image;
    if(ac ==2)
	{

		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 800, 800, "jamaica");
		image = mlx_new_image(mlx.mlx, 800, 800);
		mlx_put_image_to_window(mlx.mlx, mlx.win, image, 500, 500);
		mlx_mouse_hook(mlx.win, &ptr, 0);
		mlx_loop(mlx.mlx);
	}
}

