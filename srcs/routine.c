/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/09 15:59:50 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	print_val(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("#%d DIFF = %ld , time to die %d\n",philo->id, philo->current_time - philo->start_to_die, philo->global->time_to_die);
	pthread_mutex_unlock(&philo->global->printf);
}


int	is_death(t_philo *philo)
{
//	print_val(philo);
	if((philo->current_time - philo->start_to_die) > philo->global->time_to_die)
		return (1);
	else
		return (0);
}

void	*routine(void *arg)
{
	t_philo philo;
	
	philo = *(t_philo*) arg;

	philo.start_to_die = gettime_ms();
	if (philo.id % 2 == 0)
		ft_usleep(5);
	
	while (philo.global->number_of_meal == -1 || philo.meal_taken < philo.global->number_of_meal)
	{
		pthread_mutex_lock(&philo.global->forks[philo.left_fork]);
		philo.current_time = gettime_ms();
		print_take_left_fork(&philo);
		
		if (is_death(&philo) == 1)
		{
			print_dead(&philo);
			return (NULL);	
		}
		
		pthread_mutex_lock(&philo.global->forks[philo.right_fork]);
		philo.current_time = gettime_ms();
		print_take_right_fork(&philo);
		
		if (is_death(&philo) == 1)
		{
			print_dead(&philo);
			return (NULL);	
		}

		print_eating(&philo);
		philo.start_to_die = philo.current_time;
		ft_usleep(philo.global->time_to_eat);

		if (is_death(&philo) == 1)
		{
			print_dead(&philo);
			return (NULL);	
		}

		
		pthread_mutex_unlock(&philo.global->forks[philo.right_fork]);
		philo.current_time = gettime_ms();
	//	print_drop_right_fork(&philo);

		if (is_death(&philo) == 1)
		{
			print_dead(&philo);
			return (NULL);	
		}
		
		pthread_mutex_unlock(&philo.global->forks[philo.left_fork]);
		philo.current_time = gettime_ms();
		//print_drop_left_fork(&philo);

		if (is_death(&philo) == 1)
		{
			print_dead(&philo);
			return (NULL);	
		}

		philo.current_time = gettime_ms();
		print_sleeping(&philo);
		ft_usleep(philo.global->time_to_sleep);
	
		if (is_death(&philo) == 1)
		{
			print_dead(&philo);
			return (NULL);	
		}
		
		philo.current_time = gettime_ms();
		print_thinking(&philo);
		
		if (is_death(&philo) == 1)
		{
			print_dead(&philo);
			return (NULL);	
		}
	}
	philo.global->all_meals_taken++;
	return (NULL);
}