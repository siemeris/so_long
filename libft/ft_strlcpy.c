/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:34:26 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 07:49:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// It copies up to dstsize - 1 characters from the string src to dst, 
// NUL-terminating the result if dstsize is not 0.

// It returns the total length of the string they tried to create.  
// For strlcpy() that means the length of src. 

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	longsrc;

	longsrc = 0;
	i = 0;
	while (src[longsrc] != '\0')
		longsrc++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (longsrc);
}
