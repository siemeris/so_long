/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:12:18 by issierra          #+#    #+#             */
/*   Updated: 2023/12/10 17:56:33 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_window(t_data *prog)
{
	if (prog->exit == 1)
		ft_printf("YOU WON!\n");
	else
		ft_printf("BYE!\n");
	mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	free_map(prog->map_read);
	exit (0);
}

int	key_hook(int keycode, t_data *prog)
{
	if (keycode == ESC)
	{
		ft_printf("BYE!\n");
		mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
		free_map(prog->map_read);
		exit (0);
	}
	if (keycode == UP || keycode == W)
		go_up(prog);
	if (keycode == DOWN || keycode == A)
		go_down(prog);
	if (keycode == RIGHT || keycode == D)
		go_right(prog);
	if (keycode == LEFT || keycode == S)
		go_left(prog);
	return (0);
}

void	run_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_width * IMG_WIDTH, \
	data->map_height * IMG_HEIGHT, "Mycological Odyssey");
	ft_print_map(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		return (ft_printf("Error\nINVALID ARGUMENT\n"));
	data.map_read = check_file(argv[1]);
	if (!data.map_read)
		return (0);
	if (!check_map(&data))
	{
		free_map(data.map_read);
		return (0);
	}
	data.moves = 0;
	data.img_path = PLAYER;
	data.exit = 0;
	run_window(&data);
	mlx_loop_hook(data.mlx_ptr, update_animation, &data);
	mlx_loop(data.mlx_ptr);
}
