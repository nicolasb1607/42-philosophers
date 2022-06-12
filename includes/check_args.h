/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:24:24 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/12 11:38:32 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGS_H
# define CHECK_ARGS_H

# include "philo.h"

# define ERROR_NOT_ENOUGHT_ARGS "Error, at least 5 arguments required\n"
# define ERROR_TOO_MANY_ARGS "Error, no more than 6 arguments required\n"
# define ERROR_NOT_NUMERIC_ARGS "Error, only numeric arguments accepted\n"
# define ERROR_INT_OVERFLOW "Error, integer overflow argument\n"

void	del_zero(char *str, int i);
int		ft_is_int(char *str);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
int		is_args_valid(int ac, char **av);
int		is_number_arg_valid(int ac);
int		is_all_digit_arg(char **av);
int		is_all_int_arg(char **av);
int		is_str_number(char *str);
int		ft_atoi(const char *nptr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);

#endif
