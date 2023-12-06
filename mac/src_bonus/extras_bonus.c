/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:12:36 by issierra          #+#    #+#             */
/*   Updated: 2023/12/06 09:58:44 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	movements_on_screen(t_data *data)
{
	char	*ptr;

	ptr = ft_itoa(data->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 60, 60, 0x00000000, "Moves:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 75, 75, 0x00000000, ptr);
	free(ptr);
}

int	update_animation(t_data *data)
{
	if (data->map_read[data->monster_y + 1][data->monster_x] == '0')
	{
		data->map_read[data->monster_y][data->monster_x] = '0';
		data->map_read[data->monster_y + 1][data->monster_x] = 'M';
		data->monster_y++;
	}
	else if (data->map_read[data->monster_y - 1][data->monster_x] == '0')
	{
		data->map_read[data->monster_y][data->monster_x] = '0';
		data->map_read[data->monster_y - 1][data->monster_x] = 'M';
		data->monster_y--;
	}
	else if (data->map_read[data->monster_y][data->monster_x + 1] == 'P'
		|| data->map_read[data->monster_y][data->monster_x - 1] == 'P'
		|| data->map_read[data->monster_y + 1][data->monster_x] == 'P'
		|| data->map_read[data->monster_y - 1][data->monster_x] == 'P')
	{
		ft_printf("You have been eaten by a monster!\n");
		close_window(data);
	}
	return (0);
}
