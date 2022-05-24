/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:21:44 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/24 16:34:22 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGS_H
# define CHECK_ARGS_H

# include "philo.h"

# define ERROR_NOT_ENOUGHT_ARGS "Error, at least 5 arguments required\n"
# define ERROR_TOO_MANY_ARGS "Error, no more than 6 arguments required\n"
# define ERROR_NOT_NUMERIC_ARGS "Error, only numeric arguments accepted\n"
# define ERROR_INT_OVERFLOW "Error, integer overflow argument\n"

int	is_args_valid(int ac, char **av);
int	is_number_arg_valid(int ac);
int	is_all_digit_arg(char **av);
int	is_all_int_arg(char **av);
int	is_str_number(char *str);

#endif
