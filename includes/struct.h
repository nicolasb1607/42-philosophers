/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:22:49 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/24 17:16:24 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "philo.h"

typedef struct	s_philo
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	alive;
	
}	t_philo;

#endif