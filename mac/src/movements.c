/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:47:25 by issierra          #+#    #+#             */
/*   Updated: 2023/11/26 12:20:38 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	go_up(t_data *prog)
{
	// ft_printf("Hello from go_up! moves %i %p %p \n", prog->moves, prog->mlx_ptr, prog->win_ptr);
	// ft_printf("player_x, player_y en go_up: %d, %d\n", prog->player_x, prog->player_y);
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
		ft_printf("collect: %d\n", prog->collect);
	}
	prog->map_read[prog->player_y][prog->player_x] = '0';
	prog->map_read[prog->player_y - 1][prog->player_x] = 'P';
	prog->moves++;
	ft_printf("Movements: %i\n", prog->moves);
	prog->player_y--;
	ft_print_map(prog);
	return (0);
}

int	go_down(t_data *prog)
{
	// ft_printf("Hello from go_up! moves %i %p %p \n", prog->moves, prog->mlx_ptr, prog->win_ptr);
	// ft_printf("player_x, player_y en go_up: %d, %d\n", prog->player_x, prog->player_y);
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
		ft_printf("collect: %d\n", prog->collect);
	}
	prog->map_read[prog->player_y][prog->player_x] = '0';
	prog->map_read[prog->player_y + 1][prog->player_x] = 'P';
	prog->moves++;
	ft_printf("Movements: %i\n", prog->moves);
	prog->player_y++;
	ft_print_map(prog);
	return (0);
}

int	go_right(t_data *prog)
{
	// ft_printf("Hello from go_up! moves %i %p %p \n", prog->moves, prog->mlx_ptr, prog->win_ptr);
	// ft_printf("player_x, player_y en go_up: %d, %d\n", prog->player_x, prog->player_y);
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
		ft_printf("prog->collect: %d\n", prog->collect);
	}
	prog->map_read[prog->player_y][prog->player_x] = '0';
	prog->map_read[prog->player_y][prog->player_x + 1] = 'P';
	prog->moves++;
	ft_printf("Movements: %i\n", prog->moves);
	prog->player_x++;
	prog->img_path = PLAYER;
	ft_print_map(prog);
	return (0);
}

int	go_left(t_data *prog)
{
	// ft_printf("Hello from go_up! moves %i %p %p \n", prog->moves, prog->mlx_ptr, prog->win_ptr);
	// ft_printf("player_x, player_y en go_up: %d, %d\n", prog->player_x, prog->player_y);
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
		ft_printf("collect: %d\n", prog->collect);
	}
	prog->map_read[prog->player_y][prog->player_x] = '0';
	prog->map_read[prog->player_y][prog->player_x - 1] = 'P';
	prog->moves++;
	ft_printf("Movements: %i\n", prog->moves);
	prog->player_x--;
	prog->img_path = PLAYERL;
	ft_print_map(prog);
	return (0);
}
