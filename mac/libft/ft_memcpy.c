/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:59:12 by issierra          #+#    #+#             */
/*   Updated: 2023/09/24 09:49:43 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//It copies n bytes from memory area src to memory area dest.  
// The memory areas must not overlap.  
// Use memmove(3) if the memory areas do overlap.

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (n > 0)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return (dest);
}
