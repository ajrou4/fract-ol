/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 06:11:02 by majrou            #+#    #+#             */
/*   Updated: 2023/06/16 12:53:47 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2 && (ft_latoi(av[1]) == 1))
	{
		if (ft_latoi(av[1]) == 1)
			mand_main(&mlx);
	}
	else if (ac == 4 && ft_latoi(av[1]) == 2)
	{
		mlx.c_re = ft_atof(av[2], 0);
		mlx.c_img = ft_atof(av[3], 0);
		julia_main(&mlx);
	}
	error(1);
}
