/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:29:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/11 11:07:20 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gettime.h"

long	gettime_ms(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long start;
	long end;

	start = gettime_ms();
	end = gettime_ms();

	while ((end - start) <= ms )
	{
		usleep(100);
		end = gettime_ms();
	
	}	
}

void	ft_usleep_bis(int ms, t_philo *philo)
{
	long start;
	long end;

	start = gettime_ms();
	end = gettime_ms();
	

	while ((end - start) <= ms)
	{
		philo->current_time = gettime_ms();
		if (is_death(philo) == 0)
		{
			usleep(100);
			end = gettime_ms();
		}
		else 
			break;
	}
}