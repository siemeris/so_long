/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:23:05 by issierra          #+#    #+#             */
/*   Updated: 2023/09/24 09:40:00 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Envía el carácter ’c’ al file descriptor especificado.

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
