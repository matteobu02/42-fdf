/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:23:19 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/09 12:37:28 by mbucci           ###   ########.fr       */
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

/*int	get_height(char *path)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(path, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char *path)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	width = count_words(line, 32);
	close(fd);
	free(line);
	return (width);
}

void	fill_map(int *tab, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, 32);
	while (nums[i])
	{
		tab[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *path, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	data->height = get_height(path);
	data->width = get_width(path);
	data->map = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->map[i] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(path, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (i < data->height)
	{
		fill_map(data->map[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
}*/
