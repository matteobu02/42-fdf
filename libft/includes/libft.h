/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:05:26 by mbucci            #+#    #+#             */
/*   Updated: 2023/06/07 16:09:01 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int		ft_atoi(char *str);
void	ft_error(char *s);
void	*ft_free_tab(char **tab);
void	ft_putchar_fd(int c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c);
void	ft_strcpy(char *dst, char *src);
int		ft_strlen(const char *s);

/*** FT_PRINTF ***/

/*int		ft_printf(const char *str, ...);
void	ft_case_c(va_list argp);
void	ft_case_s(va_list argp, int *ptr);
void	ft_case_p(va_list argp, int *ptr);
void	ft_case_di(va_list argp, int *ptr);
void	ft_case_u(va_list argp, int *ptr);
void	ft_case_x(va_list argp, int c, int *ptr);
int		ft_count_chars(unsigned long n);
void	ft_utohexa(unsigned long n, int *ptr, int ca);*/

/*** GET_NEXT_LINE ***/

# define BUFFER_SIZE 10000

char	*get_next_line(int fd);
void	*free_str(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
