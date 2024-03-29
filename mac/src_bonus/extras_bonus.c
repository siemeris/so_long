/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:12:36 by issierra          #+#    #+#             */
/*   Updated: 2023/12/10 16:19:37 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	movements_on_screen(t_data *data)
{
	char	*ptr;

	ptr = ft_itoa(data->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, 25, 0x00000000, "Moves:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 45, 45, 0x00000000, ptr);
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
		ft_printf("YOU HAVE BEEN EATEN BY A MONSTER!\n");
		close_window(data);
	}
	return (0);
}

int	check_zero_chars(t_check_map *check)
{
	if (check->collect == 0 || check->exit == 0
		|| check->player == 0 || check->monster == 0)
		return (0);
	return (1);
}
