/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:49:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/25 14:33:07 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include "libft.h"
# include "struct.h"
# include "check_args.h"
# include "routine.h"
# include <stdio.h>

void	launch_prgm(char **av);

#endif