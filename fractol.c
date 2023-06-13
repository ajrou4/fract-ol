/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 06:11:02 by majrou            #+#    #+#             */
/*   Updated: 2023/06/12 22:02:46 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (ac == 2 && (ft_latoi(av[1]) == 1 || ft_latoi(av[1]) == 2))
	{
		if (ft_latoi(av[1]) == 1)
			mand_main();
		else if (ft_latoi(av[1]) == 2)
			julia_main(mlx);
	}
	else if (ac == 4 && ft_latoi(av[1]) == 2)
	{
		mlx->c_re = ft_atof(av[2], 0);
		mlx->c_img = ft_atof(av[3], 0);
		julia_main(mlx);
	}
	error(1);
}
