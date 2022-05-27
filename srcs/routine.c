/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/27 14:31:08 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	*routine(void *philo)
{
	t_philo param;

	while (1)
	{
		param = *(t_philo*) philo;
		pthread_mutex_lock(&param.global->printf);
		printf("Je suis le philo numero %d\n", param.id);
		pthread_mutex_unlock(&param.global->printf);

		//Mutex lock fourchette n
		//Mutex lock fourchette n-1
		//Reset the time left for the philo to die
		usleep(param.global->time_to_eat);
		//Mutex unlock fourchette n
		//Mutex unlock fourchette n -1
		printf("#%d is sleeping\n", param.id);
		usleep(param.global->time_to_sleep);
		printf("#%d is thinking\n", param.id);
	}
	return (NULL);
}