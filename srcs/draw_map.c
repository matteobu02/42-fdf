/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:22:56 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/10 15:30:16 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX(a,b) (a > b ? a : b)
#define MOD(x) (x < 0 ? -x : x)

void	apply_zoom(float *x, float *y, float *x1, float *y1, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
}

/*int	get_color(float x, float x1, in)
{
	int	color;
	int	distance;

	distance = sqrt(pow())
	color = 0xffffff;
	if (z || z1)
		return (color - ((x - x1) * 15000));
	else
		return (color);
}*/

void	apply_angle(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(1.085);
	*y = (*x + *y) * sin(1.085) - (2 * z);
	*x += data->shift_x;
	*y += data->shift_y;
}

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
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	apply_angle(&x, &y, z, data);
	apply_angle(&x1, &y1, z1, data);
	delta_x = x1 - x;
	delta_y = y1 - y;
	bigger = MAX(MOD(delta_x), MOD(delta_y));
	delta_x /= bigger;
	delta_y /= bigger;
	while ((int)(x - x1) || (int)(y - y1))
	{
		//data->color = get_color(x, x1, z, z1);
		mlx_pixel_put(data->mlx, data->win, x, y, data->color);
		x += delta_x;
		y += delta_y;
	}
}

void	draw_map(t_fdf *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->length)
	{
		i = -1;
		while (++i < data->width)
		{
			if (i < data->width - 1)
				draw_line(i, j, i + 1, j, data);
			if (j < data->length - 1)
				draw_line(i, j, i, j + 1, data);
		}
	}
}
