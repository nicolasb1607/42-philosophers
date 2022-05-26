/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:10:06 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/26 17:51:31 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#include "philo.h"

t_global *create_global(char **av);
t_philo *create_philo(t_global *global);
void	init_philo(t_philo *philo, int i);

#endif