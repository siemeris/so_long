/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:48:54 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 07:42:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memset() function writes len bytes of value c (converted to 
// an unsigned char) to the string b.

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (s);
}
