/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:16:57 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/10 11:49:18 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct	s_fdf
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
	//float	angle;
}	t_fdf;

void	get_data(char *path, t_fdf *data);
void	draw_map(t_fdf *data);

#endif
