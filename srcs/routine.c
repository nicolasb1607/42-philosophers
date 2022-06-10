/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/10 16:16:01 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

int	is_death(t_philo *philo)
{
	if ((philo->current_time - philo->start_to_die) > philo->global->time_to_die)
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo philo;
	
	philo = *(t_philo*) arg;

	if (philo.id % 2 == 0)
		ft_usleep(5);
	philo.start_to_die = gettime_ms();
	
	while (philo.global->number_of_meal == -1 || philo.meal_taken < philo.global->number_of_meal)
	{

/* FOURCHETTE ROUTINE */
		pthread_mutex_lock(&philo.global->forks[philo.left_fork]);
		philo.current_time = gettime_ms();
		if (is_death(&philo) == 1)
		{
			pthread_mutex_unlock(&philo.global->forks[philo.left_fork]);
			print_dead(&philo);
			return (NULL);	
		}
		print_take_fork(&philo);
		
		if (philo.global->num_of_philo == 1)
		{
			ft_usleep(philo.global->time_to_die);
			philo.current_time = gettime_ms();
			print_dead(&philo);
		}
		pthread_mutex_lock(&philo.global->forks[philo.right_fork]);
		philo.current_time = gettime_ms();
		if (is_death(&philo) == 1)
		{
			pthread_mutex_unlock(&philo.global->forks[philo.right_fork]);
			pthread_mutex_unlock(&philo.global->forks[philo.left_fork]);
			print_dead(&philo);
			return (NULL);	
		}
		print_take_fork(&philo);
		
/* MANGER ROUTINE */
		print_eating(&philo);
		//philo.current_time = gettime_ms();
		philo.start_to_die = philo.current_time;
		ft_usleep(philo.global->time_to_eat);
		philo.current_time = gettime_ms();
		if (is_death(&philo) == 1)
		{
			pthread_mutex_unlock(&philo.global->forks[philo.right_fork]);
			pthread_mutex_unlock(&philo.global->forks[philo.left_fork]);
			print_dead(&philo);
			return (NULL);	
		}
		pthread_mutex_unlock(&philo.global->forks[philo.right_fork]);		
		pthread_mutex_unlock(&philo.global->forks[philo.left_fork]);
		
		
		philo.current_time = gettime_ms();
		if (is_death(&philo) == 1)
		{
			print_dead(&philo);
			return (NULL);	
		}

/* DORMIR ROUTINE */

		print_sleeping(&philo);
		ft_usleep(philo.global->time_to_sleep);
		philo.current_time = gettime_ms();
		if (is_death(&philo) == 1)
		{
			print_dead(&philo);
			return (NULL);	
		}

/* PENSER ROUTINE */
		print_thinking(&philo);
	}
	philo.global->all_meals_taken++;
	return (NULL);
}
