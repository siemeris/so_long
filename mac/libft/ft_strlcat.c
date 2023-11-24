/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:34:23 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 07:52:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strlcat() appends string src to the end of dst.  It will append at most 
// dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless 
// dstsize is 0 or the original dst string was longer than dstsize 
// (in practice this should not happen as it means that either dstsize is 
// incorrect or that dst is not a proper string).

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	lendest;
	unsigned int	lensrc;
	unsigned int	i;
	unsigned int	k;
	unsigned int	j;

	lendest = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	j = 0;
	k = lendest;
	if (size > lendest)
	{
		while (src[i] != '\0' && j < size - lendest - 1)
		{
			dst[k] = src[i];
			k++;
			i++;
			j++;
		}
		dst[k] = '\0';
		return (lendest + lensrc);
	}
	return (lensrc + size);
}
