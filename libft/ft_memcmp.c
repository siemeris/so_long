/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:07:29 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 11:08:32 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memcmp() function compares byte string s1 against byte string s2.  
// Both strings are assumed to be n bytes long
// The memcmp() function returns zero if the two strings are identical, 
// otherwise returns the difference between the first two differing bytes 
// (treated as unsigned char values, so that `\200' is greater than `\0', 
// for example).  Zero-length strings are always identical.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
