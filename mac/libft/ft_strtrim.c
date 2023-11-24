/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:49:47 by issierra          #+#    #+#             */
/*   Updated: 2023/09/23 21:42:50 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//s1: La string que debe ser recortada.
//set: Los caracteres a eliminar de la string.

//Devuelve: La string recortada.
//NULL si falla la reserva de memoria.

// Elimina todos los caracteres de la string ’set’
// desde el principio y desde el final de ’s1’, hasta
// encontrar un caracter no perteneciente a ’set’. La
// string resultante se devuelve con una reserva de
// malloc(3)

#include "libft.h"

static int	ft_char_in_set(char const *s1, char const *set)
{
	int	k;

	k = 0;
	while (set[k])
	{
		if (set[k] == *s1)
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*res;
	int			i;

	i = 0;
	start = s1;
	end = start + ft_strlen(s1) - 1;
	while (*start && ft_char_in_set(start, set))
		start++;
	while (end > start && ft_char_in_set(end, set))
		end--;
	res = malloc(sizeof(char) * (end - start) + 2);
	if (!res)
		return (NULL);
	while (start <= end)
	{
		res[i] = *start;
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
