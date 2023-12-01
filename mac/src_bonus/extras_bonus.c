/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:12:36 by issierra          #+#    #+#             */
/*   Updated: 2023/12/01 11:58:48 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    movements_on_screen(t_data *data)
{
    char	*ptr;
    // char    *text;

    ptr = ft_itoa(data->moves);
    // text = "Moves:";
    // mlx_string_put(data->mlx_ptr, data->win_ptr, 60, 60, 0x00FF00FF, text);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 75, 75, 0x00FF00FF,  ptr);
    free(ptr);
    // free(text);
}

    
