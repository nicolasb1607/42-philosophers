/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prgm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:16:52 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/12 10:16:57 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all_struct(t_global *global)
{
	int	i;

	i = 0;
	free(global->threads);
	while (i < global->num_of_philo)
	{
		free(global->philo[i]);
		i++;
	}
	free(global->philo);
	free(global->forks);
	free(global);
}
