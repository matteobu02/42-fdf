/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:24:18 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/21 13:34:50 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_program(t_fdf *data, char *s)
{
	int	i;

	i = -1;
	if (!data->width)
	{
		free(data);
		ft_error(s);
	}
	if (data->map)
	{
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	data->mlx = NULL;
	data->win = NULL;
	free(data);
	data = NULL;
	ft_putstr_fd(s, 1);
	exit(0);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 123 || key == 65361)
		data->shift_x -= 10;
	else if (key == 124 || key == 65363)
		data->shift_x += 10;
	else if (key == 125 || key == 65364)
		data->shift_y += 10;
	else if (key == 126 || key == 65362)
		data->shift_y -= 10;
	else if (key == 257 || key == 65506)
		data->zoom += 2;
	else if (key == 258 || key == 65505)
		data->zoom -= 2;
	else if (key == 17 || key == 116)
		data->h += 0.1;
	else if (key == 11 || key == 98)
		data->h -= 0.1;
	else if (key == 53 || key == 65307)
		close_program(data, "Exit program.\n");
	else
		return (0);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2)
		ft_error("Error : invalid number of arguments.\n");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	get_data(av[1], data);
	if (!data->map)
		close_program(data, "Error.\n");
	data->mlx = mlx_init();
	if (!data->mlx)
		close_program(data, "Mlx error.\n");
	data->win = mlx_new_window(data->mlx, 1000, 1000, "FDF");
	if (!data->win)
		close_program(data, "Mlx error.\n");
	data->h = 2;
	data->zoom = 30;
	data->shift_x = 390;
	data->shift_y = 300;
	draw_map(data);
	mlx_key_hook(data->win, deal_key, data);
	mlx_loop(data->mlx);
	return (0);
}
