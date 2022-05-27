/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:47:23 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/26 16:48:25 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCH_PRGM_H
# define LAUNCH_PRGM_H

#include "philo.h"

void	set_param(t_global *global, char **av);
void	display_param(t_global global);
void	launch_prgm(char **av);

#endif