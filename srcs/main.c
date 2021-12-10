/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:24:18 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/10 12:19:58 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf *data)
{
	if (key == 123)
		data->shift_x -= 10;
	else if (key == 124)
		data->shift_x += 10;
	else if (key == 125)
		data->shift_y += 10;
	else if (key == 126)
		data->shift_y -= 10;
	else if (key == 257)
		data->zoom += 2;
	else if (key == 258)
		data->zoom -= 2;
	//else if (key == 53)
		//return (close_program(data));
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	//printf("%d\n", key);
	return (0);
}

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
	data->shift_x = 100;
	data->shift_y = 100;
	draw_map(data);
	mlx_key_hook(data->win, deal_key, data);
	mlx_loop(data->mlx);
	return (0);
}
