/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:43:23 by issierra          #+#    #+#             */
/*   Updated: 2023/09/24 09:57:15 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Envía el número ’n’ al file descriptor dado.

void	ft_putnbr_fd(int n, int fd)
{
	int	num;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		write (fd, "-", 1);
	}
	num = n % 10 + '0';
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	write(fd, &num, 1);
}
