/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/30 11:26:23 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"


void	*routine(void *philo)
{
	t_philo param;

	int i;

	i = 0;
	while (i < 5)
	{
		param = *(t_philo*) philo;
		pthread_mutex_lock(&param.left_fork);
		print_take_fork(&param);
		
		pthread_mutex_lock(&param.right_fork);
		print_take_fork(&param);
		
		print_eating(&param);
		usleep(param.global->time_to_eat);
		//Reset the time left for the philo to die

		
		pthread_mutex_unlock(&param.right_fork);
		print_drop_fork(&param);

		
		pthread_mutex_unlock(&param.left_fork);
		print_drop_fork(&param);
	
		print_sleeping(&param);
		
		usleep(param.global->time_to_sleep);
		print_thinking(&param);
		i++;
	}
	return (NULL);
}