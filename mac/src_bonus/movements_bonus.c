/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:47:25 by issierra          #+#    #+#             */
/*   Updated: 2023/12/01 12:02:06 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	go_up(t_data *prog)
{
	if (prog->map_read[prog->player_y - 1][prog->player_x] == '1')
		return (0);
	if (prog->map_read[prog->player_y - 1][prog->player_x] == 'E')
	{
		if (prog->exit == 1)
			close_window(prog);
		return (0);
	}
	if (prog->map_read[prog->player_y - 1][prog->player_x] == 'C')
	{
		prog->collect--;
		if (prog->collect == 0)
			prog->exit = 1;
	}
	prog->map_read[prog->player_y][prog->player_x] = '0';
	prog->map_read[prog->player_y - 1][prog->player_x] = 'P';
	prog->moves++;
	ft_printf("Movements: %i\n", prog->moves);
	prog->player_y--;
	ft_print_map(prog);
	// movements_on_screen(prog);
	return (0);
}

int	go_down(t_data *prog)
{
	if (prog->map_read[prog->player_y + 1][prog->player_x] == '1')
		return (0);
	if (prog->map_read[prog->player_y + 1][prog->player_x] == 'E')
	{
		if (prog->exit == 1)
			close_window(prog);
		return (0);
	}
	if (prog->map_read[prog->player_y + 1][prog->player_x] == 'C')
	{
		prog->collect--;
		if (prog->collect == 0)
			prog->exit = 1;
	}
	prog->map_read[prog->player_y][prog->player_x] = '0';
	prog->map_read[prog->player_y + 1][prog->player_x] = 'P';
	prog->moves++;
	ft_printf("Movements: %i\n", prog->moves);
	prog->player_y++;
	ft_print_map(prog);
	// movements_on_screen(prog);

	return (0);
}

int	go_right(t_data *prog)
{
	if (prog->map_read[prog->player_y][prog->player_x + 1] == '1')
		return (0);
	if (prog->map_read[prog->player_y][prog->player_x + 1] == 'E')
	{
		if (prog->exit == 1)
			close_window(prog);
		return (0);
	}
	if (prog->map_read[prog->player_y][prog->player_x + 1] == 'C')
	{
		prog->collect--;
		if (prog->collect == 0)
			prog->exit = 1;
	}
	prog->map_read[prog->player_y][prog->player_x] = '0';
	prog->map_read[prog->player_y][prog->player_x + 1] = 'P';
	prog->moves++;
	ft_printf("Movements: %i\n", prog->moves);
	prog->player_x++;
	prog->img_path = PLAYER;
	ft_print_map(prog);
	// movements_on_screen(prog);

	return (0);
}

int	go_left(t_data *prog)
{
	if (prog->map_read[prog->player_y][prog->player_x - 1] == '1')
		return (0);
	if (prog->map_read[prog->player_y][prog->player_x - 1] == 'E')
	{
		if (prog->exit == 1)
			close_window(prog);
		return (0);
	}
	if (prog->map_read[prog->player_y][prog->player_x - 1] == 'C')
	{
		prog->collect--;
		if (prog->collect == 0)
			prog->exit = 1;
	}
	prog->map_read[prog->player_y][prog->player_x] = '0';
	prog->map_read[prog->player_y][prog->player_x - 1] = 'P';
	prog->moves++;
	ft_printf("Movements: %i\n", prog->moves);
	prog->player_x--;
	prog->img_path = PLAYERL;
	ft_print_map(prog);
	// movements_on_screen(prog);

	return (0);
}
