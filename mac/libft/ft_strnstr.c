/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:52:12 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 11:40:43 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strnstr() function locates the first occurrence of the null-terminated 
// string needle in the string haystack, where not more than len characters 
// are searched.  Characters that appear after a `\0' character are not 
// searched.

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] != '\0'
				&& haystack[i + j] == needle[j] && (i + j) < len)
				j++;
			if (needle[j] == '\0' && j <= len)
				return ((char *)&haystack[i]);
			else
			{
				j = 0;
			}
		}
		i++;
	}
	i = 0;
	return (0);
}
