/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:38:49 by majrou            #+#    #+#             */
/*   Updated: 2023/06/03 04:11:55 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    error(int a)
{
    if(a == 1)
    {
        write(2, "you have problem\n", 18);
		write(2, "if you want mandelbrot\n", 24);
		write(2, "write like this : ./fractol  1\n", 32);
		write(2, "if you want julia write : ././fractol  num_r num_i\n", 52);
		write(2, "num_r : real part {1 1,5 2 ...}\n", 21);
		write(2, "num_i :imaginary part{5i 5.1i 6 ...}\n", 18);
        exit;
    }
}

long	ft_latoi(char	*str)
{
	long	res;
	size_t	i;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			error (1);
	}
	return (res * sign);
}