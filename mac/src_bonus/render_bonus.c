/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:45:43 by issierra          #+#    #+#             */
/*   Updated: 2023/12/04 11:43:17 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(int x, int y, t_data data, char *path)
{
	data.img = mlx_xpm_file_to_image(data.mlx_ptr, path, &data.img_width, \
	&data.img_height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
	data.img, x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	put_player(int x, int y, t_data *data)
{
	data->player_x = x;
	data->player_y = y;
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path, \
	&data->img_width, &data->img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->img, x * IMG_WIDTH, y * IMG_HEIGHT);
}

int	ft_print_map(t_data *data)
{
	size_t		w;
	size_t		h;

	w = 0;
	h = 0;
	while (h < data->map_height)
	{
		while (w < data->map_width)
		{
			put_img(w, h, *data, BACKGROUND);
			if (data->map_read[h][w] == '1')
				put_img(w, h, *data, WALL);
			else if (data->map_read[h][w] == 'C')
				put_img(w, h, *data, COLLECT);
			else if (data->map_read[h][w] == 'E')
				put_img(w, h, *data, EXIT);
			else if (data->map_read[h][w] == 'P')
				put_player(w, h, data);
			else if (data->map_read[h][w] == 'M')
				put_img(w, h, *data, MONSTER);
			w++;
		}
		w = 0;
		h++;
	}
	movements_on_screen(data);
	return (0);
}
