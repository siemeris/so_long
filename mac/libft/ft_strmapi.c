/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:12:25 by issierra          #+#    #+#             */
/*   Updated: 2023/09/23 21:50:57 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A cada carácter de la string ’s’, aplica la
// función ’f’ dando como parámetros el índice de cada
// carácter dentro de ’s’ y el propio carácter. Genera
// una nueva string con el resultado del uso sucesivo
// de ’f’

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	while (res[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
