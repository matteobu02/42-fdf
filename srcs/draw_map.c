/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:22:56 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/08 13:38:37 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	find_abs(float x)
{
	if (x > 0)
		return (x);
	else
		return (-x);
}

int	find_bigger(float x1, float x2)
{
	if (x1 > x2)
		return (x1);
	else
		return (x2);
}

void	apply_zoom(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}

/*void	apply_angle(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}*/

void	draw_line(float x, float y, float x1, float y1, t_fdf *data)
{
	float	delta_x;
	float	delta_y;
	int		bigger;
	int		z;
	int		z1;

	z = data->map[(int)y][(int)x];
	z1 = data->map[(int)y1][(int)x1];
	apply_zoom(&x, &y, &x1, &y1, data);
	delta_x = x1 - x;
	delta_y = y1 - y;
	//apply_angle(&x, &y, z);
	//apply_angle(&x1, &y1, z1);
	bigger = find_bigger(find_abs(delta_x), find_abs(delta_y));
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	delta_x /= bigger;
	delta_y /= bigger;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx, data->win, x, y, data->color);
		x += delta_x;
		y += delta_y;
	}
}

void	draw_map(t_fdf *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->length)
	{
		i = 0;
		while (i < data->width)
		{
			if (i < data->width - 1)
				draw_line(i, j, i + 1, j, data);
			if (j < data->length - 1)
				draw_line(i, j, i, j + 1, data);
			i++;
		}
		j++;
	}
}
