/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:03:56 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 11:18:13 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Si start está fuera de los límites de s, se devuelve una cadena vacía, 
//reservandoe el correspondiente espacio de memoria 
//Si no se puede asignar memoria para la nueva cadena, se devuelve 
//un puntero nulo
//Si la long de la cadena original es menor que len, se devuelve la long 
//de la cadena original
//strlcpy incluye el nulo

// Reserva (con malloc(3)) y devuelve una substring de la string ’s’.
// La substring empieza desde el índice ’start’ y tiene una longitud 
// máxima ’len’.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	i = ft_strlen(s);
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((i - start) < len)
		len = i - start;
	res = malloc(sizeof(char) * (len + 1));
	if (res && start < i)
	{
		s = s + start;
		ft_strlcpy(res, s, len + 1);
		return (res);
	}
	return (NULL);
}
