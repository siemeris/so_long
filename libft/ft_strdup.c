/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:37:49 by issierra          #+#    #+#             */
/*   Updated: 2023/09/23 21:57:01 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strdup() function allocates sufficient memory for a copy of the string 
//s1, does the copy, and returns a pointer to it.  The pointer may subsequently 
// be used as an argument to the function free(3). 
//If insufficient memory is available, NULL is returned and errno is set to 
//ENOMEM.

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		len;

	len = ft_strlen(s1);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		res[len] = s1[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}
