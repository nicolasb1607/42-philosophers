/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:53:41 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/30 21:43:58 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_MSG_H
# define PRINT_MSG_H

# include "philo.h"

void	print_take_fork(t_philo *philo);
void	print_eating(t_philo *philo);
void	print_sleeping(t_philo *philo);
void	print_thinking(t_philo *philo);
void	print_drop_fork(t_philo *philo);
void	print_take_left_fork(t_philo *philo);
void	print_take_right_fork(t_philo *philo);
void	print_drop_left_fork(t_philo *philo);
void	print_drop_right_fork(t_philo *philo);
void	print_dead(t_philo *philo);


#endif