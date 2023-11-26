/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:17:04 by issierra          #+#    #+#             */
/*   Updated: 2023/11/26 10:09:43 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// SE DEBE COMPROBAR:
// 1. Que el mapa sea rectangular
// 2. Que el mapa tenga al menos un coleccionable (C)
// 3. Que el mapa tenga al menos una salida (E)
// 4. Que el mapa tenga al menos un jugador (P)
// 5. Que el mapa tenga al menos un muro alrededor (1)
// 6. Que el mapa tenga al menos un camino válido (0)

// int ft_print_error(int error)
// {
// 	if (error == 1)
// 		ft_printf("Error\nMAPA INVALIDO, NO RECTANGULAR\n");
// 	else if (error == 2)
// 		ft_printf("Error\nMAPA INVALIDO, CARACTER INVALIDO\n");
// 	else if (error == 3)
// 		ft_printf("Error\nMAPA INVALIDO, NO HAY COLECCIONABLES, SALIDA O JUGADOR\n");
// 	else if (error == 4)
// 		ft_printf("Error\nMAPA INVALIDO, MAS DE UNA SALIDA\n");
// 	else if (error == 5)
// 		ft_printf("Error\nMAPA INVALIDO, MAS DE UN JUGADOR\n");
// 	else if (error == 6)
// 		ft_printf("Error\nMAPA INVALIDO, NO RODEADO DE MUROS\n");
// 	else if (error == 7)
// 		ft_printf("Error\nMAPA INVALIDO, CAMINO NO VALIDO\n");
// 	return (0);
// }


int	flood_fill(t_check_map *map, size_t x, size_t y)
{
	ft_printf("HELLO FROM FLOOD FILL map_copy0 = %s x = %d, y = %d w = %d h = %d \n", map->map_copy[0], x, y, map->w, map->h);
	if (x < 0 || x >= map->w || y < 0 || y >= map->h || map->map_copy[y][x] == '1' || map->map_copy[y][x] == 'F')
        return (0);
    map->map_copy[y][x] = 'F';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
    return (1);
}

int check_path(t_check_map *check, t_data *data)
{
		//COMPROBAR CAMINO VALIDO
    ///hacemos una copia del mapa    
    check->map_copy = ft_calloc(data->map_height + 1, sizeof(char *));
    if (!check->map_copy)
        return (0);
    size_t i = 0;
    while (i < data->map_height)
    {
        check->map_copy[i] = ft_strdup(data->map_read[i]);
        if (!check->map_copy[i])
            return (0);
        i++;
    }
    check->w = data->map_width;
    check->h = data->map_height;
	flood_fill(check, data->player_x, data->player_y);
        //Imprimimos map_copy
    i=0;
    while (i < check->h)
    {
        ft_printf("%s\n", check->map_copy[i]);
        i++;
    }
    //Comprobamos que no haya ningun C y ningun E
    i=0;
    while (i < check->h)
    {
        if (ft_strchr(check->map_copy[i], 'C') || ft_strchr(check->map_copy[i], 'E'))
			return(ft_print_error(7));
        i++;
    }
	return (1);
}

int check_chars(t_check_map *check, t_data *data)
{
	while (check->h < data->map_height)
	{
		while (check->w < data->map_width)
		{
			if (data->map_read[check->h][check->w] != '0' && data->map_read[check->h][check->w] != '1' && data->map_read[check->h][check->w] != 'C' && data->map_read[check->h][check->w] != 'E' && data->map_read[check->h][check->w] != 'P')
				return (ft_print_error(2));
			else if (data->map_read[check->h][check->w] == 'C')
			 	check->collect++;
			else if (data->map_read[check->h][check->w] == 'E')
			{ 
			 	check->exit++;
				if (check->exit != 1)
					return (ft_print_error(4));
			}
			else if (data->map_read[check->h][check->w] == 'P')
			{
				check->player++;
				//guardamos la posicion del jugador
				data->player_x = check->w;
				data->player_y = check->h;
				if (check->player > 1)
					return (ft_print_error(5));
			}
			if (check->w == 0 || check->h == 0)
			{
				if (data->map_read[check->h][check->w] != '1')
					return (ft_print_error(6));
			}
			check->w++;
		}
		check->w = 0;
		check->h++;
	}
	return (1);
}

int check_map(t_data *data)
{
	t_check_map	*check;

    check = ft_calloc(1, sizeof(t_check_map));
	if (!check)
		return (0);
	data->map_height = 0;
	data->map_width = ft_strlen(data->map_read[0]);
	while (data->map_read[data->map_height])
	{
		if (ft_strlen(data->map_read[data->map_height]) != data->map_width)
			return (ft_print_error(1));
		data->map_height++;
	}
	if (!check_chars(check, data))
		return (0);
	if (check->collect == 0 || check->exit == 0 || check->player == 0)
		return (ft_print_error(3));
	if (!check_path(check, data))
		return (0);
	data->collect = check->collect;
	ft_printf("MAPA VALIDO\n");
	free_map(check->map_copy);
	free(check);
	return (1);
}