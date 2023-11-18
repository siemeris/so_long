/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:20:10 by issierra          #+#    #+#             */
/*   Updated: 2023/09/26 09:39:21 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// lst: un puntero al primer nodo.
// f: un puntero a la función que utilizará cada nodo.
// Itera la lista ’lst’ y aplica la función ’f’ en el
// contenido de cada nodo.

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*aux;

	aux = lst;
	if (!lst || !f)
		return ;
	while (aux)
	{
		(*f)(aux->content);
		aux = aux->next;
	}
}
