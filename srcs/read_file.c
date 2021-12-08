/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:23:19 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/07 12:50:37 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char *s, int c)
{
	int	i;
	int	flag;
	int	count;

	i = -1;
	count = 0;
	flag = 0;
	while (s[++i])
	{
		if (s[i] == c && flag == 1)
			flag = 0;
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
	}
	return (count);
}

void	get_dimentions(char *path, t_fdf *data)
{
	int 	fd;
	int		length;
	char	*line;

	fd = open(path, O_RDONLY);
	length = 0;
	line = get_next_line(fd);
	data->width = count_words(line, 32);
	while (line)
	{
		length++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->length = length;
}

void	fill_map(char *path, t_fdf *data)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**nums;

	fd = open(path, O_RDONLY);
	i = -1;
	while (++i < data->length)
	{
		j = -1;
		line = get_next_line(fd);
		nums = ft_split(line, 32);
		while (++j < data->width)
			data->map[i][j] = ft_atoi(nums[j]);
		free(line);
		nums = ft_free_tab(nums);
	}
	close(fd);
}

void	get_data(char *path, t_fdf *data)
{
	int	i;

	get_dimentions(path, data);
	data->map = (int **)malloc(sizeof(int *) * (data->length + 1));
	if (!data->map)
		return ;
	i = -1;
	while (++i <= data->length)
	{
		data->map[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!data->map[i])
		{
			while (i > -1)
				free(data->map[i--]);
			free(data->map);
			data->map = 0;
			return ;
		}
	}
	fill_map(path, data);
}
