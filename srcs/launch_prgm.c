/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:10:23 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/24 15:47:12 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_print(void *i)
{
	printf("i am thread num #%d\n", *(int *) i);
	return NULL;
}

void	launch_prgm(int ac, char **av)
{
	pthread_t t1;
	//pthread_t t2;
	int i;

	(void)ac;
	(void)av;

	i = 1;
	pthread_create(&t1, NULL, &thread_print, &i);
	pthread_join(t1, NULL);
	return ;
}