/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:22:49 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/30 13:51:28 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct	s_global
{
	int 			num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_t		*threads;
	struct	s_philo	**philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printf;
}	t_global;

typedef struct	s_philo
{
	int					id;
	int					is_alive;
	int					left_fork;
	int					right_fork;
	struct	s_global	*global;
}	t_philo;


#endif