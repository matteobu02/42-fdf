/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:24:18 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/08 13:32:43 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2)
		ft_error("Error : no map.\n");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	get_data(av[1], data);
	if (!data->map)
	{
		ft_error("Error.\n");
		free(data);
	}
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "FDF");
	//data->angle = 0.8;
	data->zoom = 20;
	draw_map(data);
	//mlx_key_hook(data->win, deal_key, 0);
	mlx_loop(data->mlx);
	return (0);
}
