/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/27 10:47:02 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	*routine(void *philo)
{
	t_philo *param;

	param = (t_philo*) philo;
	printf("Je suis le philo numero %d\n", (*param).id);
	
	printf("Philo #%d dors\n", (*param).id);
	return (NULL);
}