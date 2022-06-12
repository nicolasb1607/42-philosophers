/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:31:45 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/12 11:05:04 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_DEATH_H
# define CHECK_DEATH_H

# include "philo.h"

int		is_death(t_philo *philo);
int		check_death_1_fork(t_philo *philo);
int		check_death_2_fork(t_philo *philo);
int		check_death_classic(t_philo *philo);

#endif