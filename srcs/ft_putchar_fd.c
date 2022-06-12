/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:42:15 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/12 11:38:16 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"

/* Écrit le caractère ’c’ sur le file descriptor
donné

#1. Le caractère à écrire.
#2. Le file descriptor sur lequel écrire. */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main()
{
	int fd = 1; 
	char c = 'a';
	
	ft_putchar_fd(c, fd);
	return 0;
} */
