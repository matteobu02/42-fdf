/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:22:56 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/21 12:40:15 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_coor *coos, t_fdf *data)
{
	float	delta_x;
	float	delta_y;
	int		max;

	coos->z = data->map[(int)coos->y][(int)coos->x];
	coos->z1 = data->map[(int)coos->y1][(int)coos->x1];
	apply_zoom(coos, data);
	if (coos->z || coos->z1)
		data->color = 0xff0000;
	else if (!coos->z && !coos->z1)
		data->color = 0xffffff;
	apply_angle(coos, data);
	delta_x = coos->x1 - coos->x;
	delta_y = coos->y1 - coos->y;
	max = ft_max(ft_abs(delta_x), ft_abs(delta_y));
	delta_x /= max;
	delta_y /= max;
	while ((int)(coos->x - coos->x1) || (int)(coos->y - coos->y1))
	{
		mlx_pixel_put(data->mlx, data->win, coos->x, coos->y, data->color);
		coos->x += delta_x;
		coos->y += delta_y;
	}
}

void	draw_map(t_fdf *data)
{
	int		i;
	t_coor	*coos;

	coos = (t_coor *)malloc(sizeof(t_coor));
	i = -1;
	while (++i < data->length)
	{
		coos->y = i;
		draw_map_1(data, i, coos);
	}
	free(coos);
	coos = NULL;
}

void	draw_map_1(t_fdf *data, int j, t_coor *coos)
{
	int	i;

	i = -1;
	while (++i < data->width)
	{
		coos->x = i;
		if (i < data->width - 1)
		{
			coos->x1 = i + 1;
			coos->y1 = j;
			draw_line(coos, data);
			coos->x = i;
		}
		coos->y = j;
		if (j < data->length - 1)
		{
			coos->x1 = i;
			coos->y1 = j + 1;
			draw_line(coos, data);
		}
		coos->y = j;
	}
}
