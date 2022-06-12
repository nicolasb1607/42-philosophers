/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/12 09:43:12 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

int	is_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->mutex_stop);
	if ((philo->current_time - philo->start_to_die) > philo->global->time_to_die || philo->global->stop == 1)
	{
		pthread_mutex_unlock(&philo->global->mutex_stop);
		return (1);
	}
	pthread_mutex_unlock(&philo->global->mutex_stop);
	return (0);
}

void	*routine(void *arg)
{
	t_philo philo;
	
	philo = *(t_philo*) arg;

	if (philo.id % 2 == 0)
		ft_usleep(10);
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
			ft_usleep_bis(philo.global->time_to_die, &philo);
			philo.current_time = gettime_ms();
			pthread_mutex_unlock(&philo.global->forks[philo.left_fork]);
			print_dead(&philo);
			return (NULL);	
		}
		//fprintf(stderr, "1");
		pthread_mutex_lock(&philo.global->forks[philo.right_fork]);
		//fprintf(stderr, "2");
		philo.current_time = gettime_ms();
		if (is_death(&philo) == 1)
		{
			//fprintf(stderr, "3");
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
		ft_usleep_bis(philo.global->time_to_eat, &philo);
		philo.current_time = gettime_ms();
		//fprintf(stderr, "4");
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
		ft_usleep_bis(philo.global->time_to_sleep, &philo);
		philo.current_time = gettime_ms();
		if (is_death(&philo) == 1)
		{
			print_dead(&philo);
			return (NULL);	
		}

/* PENSER ROUTINE */
		print_thinking(&philo);
	}
	pthread_mutex_lock(&philo.global->mutex_meals_taken);
	philo.global->all_meals_taken++;
	pthread_mutex_unlock(&philo.global->mutex_meals_taken);
	return (NULL);
}
