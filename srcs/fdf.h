/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:16:57 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/21 15:12:33 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_fdf
{
	int		**map;
	void	*mlx;
	void	*win;
	int		length;
	int		width;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	h;
}	t_fdf;

typedef struct s_coor
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		z;
	int		z1;
}	t_coor;

void	get_data(char *path, t_fdf *data);
void	close_program(t_fdf *data, char *s);
float	ft_abs(float x);
float	ft_max(float a, float b);
void	draw_map(t_fdf *data);
void	draw_map_1(t_fdf *data, int j, t_coor *coos);
void	apply_zoom(t_coor *coos, t_fdf *data);
void	apply_angle(t_coor *coos, t_fdf *data);

#endif
