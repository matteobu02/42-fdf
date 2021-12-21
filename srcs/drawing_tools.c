/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:42:07 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/14 23:16:22 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

float	ft_max(float a, float b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

void	apply_zoom(t_coor *coos, t_fdf *data)
{
	coos->x *= data->zoom;
	coos->y *= data->zoom;
	coos->x1 *= data->zoom;
	coos->y1 *= data->zoom;
}

void	apply_angle(t_coor *coos, t_fdf *data)
{
	coos->x = (coos->x - coos->y) * cos(1.085);
	coos->y = (coos->x + coos->y) * sin(1.085) - (data->h * coos->z);
	coos->x += data->shift_x;
	coos->y += data->shift_y;
	coos->x1 = (coos->x1 - coos->y1) * cos(1.085);
	coos->y1 = (coos->x1 + coos->y1) * sin(1.085) - (data->h * coos->z1);
	coos->x1 += data->shift_x;
	coos->y1 += data->shift_y;
}
