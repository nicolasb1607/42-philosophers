/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:52:50 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/10 22:10:00 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETTIME_H
# define GETTIME_H

# include "philo.h"

long	gettime_ms(void);
void	ft_usleep(int ms);
void	ft_usleep_bis(int ms, t_philo *philo);



#endif