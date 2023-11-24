/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:23:40 by issierra          #+#    #+#             */
/*   Updated: 2023/09/24 11:01:50 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reserva (utilizando malloc(3)) un array de strings resultante de separar 
// la string ’s’ en substrings utilizando el caracter ’c’ como delimitador. 
// El array debe terminar con un puntero NULL.

// Devuelve: El array de nuevas strings resulatente de la separación.
// NULL si falla la reserva de memoria.

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int			count;
	int			ini_word;
	char const	*temp;

	temp = s;
	count = 0;
	ini_word = 0;
	while (*temp)
	{
		if (*temp != c)
			ini_word = 1;
		if (*temp == c && ini_word == 1)
		{
			count++;
			ini_word = 0;
		}
		temp++;
	}
	if (ini_word == 1)
		count++;
	return (count);
}

static int	ft_len_word(char const *s, char c)
{
	char const	*temp;
	int			len;

	temp = s;
	len = 0;
	while (*temp != c && *temp != '\0')
	{
		len++;
		temp++;
	}
	return (len);
}

static char	**ft_free(char **res, int w)
{
	while (w >= 0)
	{
		free(res[w]);
		w--;
	}
	free(res);
	return (NULL);
}

static char	**ft_copy(char const *s, char c, char **res, int num_words)
{
	int		w;
	int		l;

	w = 0;
	while (w < num_words)
	{
		l = 0;
		while (*s == c)
			s++;
		res[w] = malloc(sizeof(char) * (ft_len_word(s, c) + 1));
		if (!res[w])
		{
			ft_free(res, w);
			return (NULL);
		}
		while (*s != c && *s != '\0')
		{
			res[w][l++] = *s;
			s++;
		}
		res[w++][l] = '\0';
	}
	res[w] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		num_words;

	num_words = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (num_words + 1));
	if (!res || !s)
		return (NULL);
	res = ft_copy(s, c, res, num_words);
	return (res);
}
