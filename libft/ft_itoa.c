/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:06:22 by issierra          #+#    #+#             */
/*   Updated: 2023/09/24 11:28:18 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Utilizando malloc(3), genera una string que
// representa el valor entero recibido como argumento.
// Los números negativos se gestionan.

#include "libft.h"

static int	ft_len_int(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_neg_case(int n, int len)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[0] = '-';
	res[len] = '\0';
	len--;
	n = n * -1;
	while (len > 0)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (res);
}

static char	*ft_pos_case(int n, int len)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		len;

	len = ft_len_int(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		return (ft_neg_case(n, len));
	}
	else
	{
		return (ft_pos_case(n, len));
	}
}
