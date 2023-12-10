/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:09:22 by issierra          #+#    #+#             */
/*   Updated: 2023/12/10 15:23:50 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_print_error(int error)
{
	if (error == 8)
		ft_printf("Error\nHubo un error al leer el archivo, \
o mapa en blanco.\n");
	else if (error == 9)
		ft_printf("Error\nMAPA NO VÁLIDO. EMPTY LINES.\n");
	else if (error == 1)
		ft_printf("Error\nMAPA INVÁLIDO, NO RECTANGULAR.\n");
	else if (error == 2)
		ft_printf("Error\nMAPA INVÁLIDO, CARACTER INVALIDO.\n");
	else if (error == 3)
		ft_printf("Error\nMAPA INVÁLIDO, \
NO HAY COLECCIONABLES, SALIDA, JUGADOR O MONSTRUO.\n");
	else if (error == 4)
		ft_printf("Error\nMAPA INVÁLIDO, MAS DE UNA SALIDA.\n");
	else if (error == 5)
		ft_printf("Error\nMAPA INVÁLIDO, MAS DE UN JUGADOR.\n");
	else if (error == 6)
		ft_printf("Error\nMAPA INVÁLIDO, NO RODEADO DE MUROS.\n");
	else if (error == 7)
		ft_printf("Error\nMAPA INVÁLIDO, CAMINO NO VÁLIDO.\n");
	else if (error == 10)
		ft_printf("Error\nMÁS DE UN MONSTRUO.\n");
	else if (error == 11)
		ft_printf("Error\nFICHERO NO ENCONTRADO.\n");
	return (0);
}
