/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:29:05 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/30 17:30:34 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gettime.h"

long	gettime_ms(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
