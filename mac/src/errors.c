/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:09:22 by issierra          #+#    #+#             */
/*   Updated: 2023/12/10 12:50:44 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_error(int error)
{
	if (error == 8)
		ft_printf("Error\nHubo un error al leer el archivo, \
o mapa en blanco.\n");
	else if (error == 9)
		ft_printf("Error\nMAPA NO VÁLIDO. EMPTY LINES\n");
	else if (error == 1)
		ft_printf("Error\nMAPA INVALIDO, NO RECTANGULAR\n");
	else if (error == 2)
		ft_printf("Error\nMAPA INVALIDO, CARACTER INVALIDO\n");
	else if (error == 3)
		ft_printf("Error\nMAPA INVALIDO, \
NO HAY COLECCIONABLES, SALIDA O JUGADOR\n");
	else if (error == 4)
		ft_printf("Error\nMAPA INVALIDO, MAS DE UNA SALIDA\n");
	else if (error == 5)
		ft_printf("Error\nMAPA INVALIDO, MAS DE UN JUGADOR\n");
	else if (error == 6)
		ft_printf("Error\nMAPA INVALIDO, NO RODEADO DE MUROS\n");
	else if (error == 7)
		ft_printf("Error\nMAPA INVALIDO, CAMINO NO VALIDO\n");
	return (0);
}
