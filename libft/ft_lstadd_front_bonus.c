/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:04:52 by issierra          #+#    #+#             */
/*   Updated: 2023/09/26 09:34:33 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// lst: la dirección de un puntero al primer nodo de
// una lista.
// new: un puntero al nodo que añadir al principio de
// la lista.

// Añade el nodo ’new’ al principio de la lista ’lst’.

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
