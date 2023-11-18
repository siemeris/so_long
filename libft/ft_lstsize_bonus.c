/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:15:48 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 11:37:44 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cuenta el número de nodos de una lista.

int	ft_lstsize(t_list *lst)
{
	int	l;

	l = 0;
	while (lst)
	{
		l++;
		lst = lst -> next;
	}
	return (l);
}
