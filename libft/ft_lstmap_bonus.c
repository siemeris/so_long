/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:20:48 by issierra          #+#    #+#             */
/*   Updated: 2023/10/01 12:45:41 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// lst: un puntero a un nodo.
// f: la dirección de un puntero a una función usada
// en la iteración de cada elemento de la lista.
// del: un puntero a función utilizado para eliminar
// el contenido de un nodo, si es necesario.

// devuelve La nueva lista.
// NULL si falla la reserva de memoria.

// Itera la lista ’lst’ y aplica la función ’f’ al
// // contenido de cada nodo. Crea una lista resultante
// de la aplicación correcta y sucesiva de la función
// ’f’ sobre cada nodo. La función ’del’ se utiliza
// para eliminar el contenido de un nodo, si hace
// falta.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlist;
	void	*content;

	newlist = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{	
		content = f(lst->content);
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			del(content);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
