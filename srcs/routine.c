/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/30 14:23:07 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"


void	*routine(void *philo)
{
	t_philo param;
	int i;

	i = 0;
	while (i < 3)
	{
		param = *(t_philo*) philo;
		pthread_mutex_lock(&param.global->forks[param.left_fork]);
		print_take_fork(&param);
		
		pthread_mutex_lock(&param.global->forks[param.right_fork]);
		print_take_fork(&param);
		
		print_eating(&param);
		usleep(param.global->time_to_eat);
		//Reset the time left for the philo to die

		
		pthread_mutex_unlock(&param.global->forks[param.right_fork]);
		print_drop_fork(&param);

		
		pthread_mutex_unlock(&param.global->forks[param.left_fork]);
		print_drop_fork(&param);
	
		print_sleeping(&param);
		
		usleep(param.global->time_to_sleep);
		print_thinking(&param);
		i++;
	}
	return (NULL);
}