/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:47:23 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/11 16:07:23 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCH_PRGM_H
# define LAUNCH_PRGM_H

#include "philo.h"

void	display_param(t_global global);
void	launch_prgm(char **av);
int		is_all_meals_taken(t_global *global);
void free_all_struct(t_global *global);

#endif