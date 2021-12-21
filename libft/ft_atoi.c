/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:19:16 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/21 13:41:01 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int					i;
	int					s;
	unsigned long int	n;

	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	s = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	n = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		if (n > 2147483647 && s == 1)
			return (-1);
		if (n > 2147483648 && s == -1)
			return (0);
		i++;
	}
	return (n * s);
}
