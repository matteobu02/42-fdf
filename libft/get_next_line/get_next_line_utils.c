/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:40:31 by mbucci            #+#    #+#             */
/*   Updated: 2021/12/06 16:06:16 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*free_str(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*join;

	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	join = (char *)malloc(len + 1);
	if (!join)
		return (free_str(s1));
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	slen;
	size_t	i;

	if (!s || !*s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen >= len)
		s2 = (char *)malloc(len + 1);
	else
		s2 = (char *)malloc(slen);
	if (!s2)
		return (NULL);
	i = 0;
	if (start <= (unsigned int)slen)
	{
		while (s[start + i] != '\0' && i < len)
		{
			s2[i] = s[start + i];
			i++;
		}
	}
	s2[i] = '\0';
	return (s2);
}
