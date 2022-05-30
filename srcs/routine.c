/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/30 21:17:33 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"


void	*routine(void *philo)
{
	t_philo param;
	int i;

	i = 0;
		
	param = *(t_philo*) philo;
	while (i < param.global->number_of_meal || param.global->number_of_meal == -1)
	{
		pthread_mutex_lock(&param.global->forks[param.left_fork]);
		param.time = gettime_ms();
		print_take_fork(&param);
		
		
		pthread_mutex_lock(&param.global->forks[param.right_fork]);
		param.time = gettime_ms();
		print_take_fork(&param);
		
		param.time = gettime_ms();
		print_eating(&param);
		usleep(param.global->time_to_eat);
		//Reset the time left for the philo to die

		pthread_mutex_unlock(&param.global->forks[param.right_fork]);
		param.time = gettime_ms();
		print_drop_fork(&param);

		pthread_mutex_unlock(&param.global->forks[param.left_fork]);
		param.time = gettime_ms();
		print_drop_fork(&param);
	
		param.time = gettime_ms();
		print_sleeping(&param);
		
		usleep(param.global->time_to_sleep);
		param.time = gettime_ms();
		print_thinking(&param);
		i++;
	}
	return (NULL);
}