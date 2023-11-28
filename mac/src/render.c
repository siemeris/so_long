/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:45:43 by issierra          #+#    #+#             */
/*   Updated: 2023/11/28 12:04:37 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_xpm_file_to_image(t_data *data)
{
	data->background = mlx_xpm_file_to_image(data->mlx_ptr, BACKGROUND, \
	&data->img_width, &data->img_height);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, \
	&data->img_width, &data->img_height);
	data->playerL = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERL, \
	&data->img_width, &data->img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL, \
	&data->img_width, &data->img_height);
	data->img_collect = mlx_xpm_file_to_image(data->mlx_ptr, COLLECT, \
	&data->img_width, &data->img_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, \
	&data->img_width, &data->img_height);
}

void	put_img(int x, int y, t_data data, void *img)
{
	// data.img = mlx_xpm_file_to_image(data.mlx_ptr, path, &data.img_width, \
	// &data.img_height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
	img, x * IMG_WIDTH, y * IMG_HEIGHT);
	ft_printf("data img %p\n", img);

}

void	put_player(int x, int y, t_data *data, void *img)
{
	data->player_x = x;
	data->player_y = y;


	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	img, x * IMG_WIDTH, y * IMG_HEIGHT);
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
			put_img(w, h, *data, data->background);
			if (data->map_read[h][w] == '1')
				put_img(w, h, *data, data->wall);
			else if (data->map_read[h][w] == 'C')
				put_img(w, h, *data, data->img_collect);
			else if (data->map_read[h][w] == 'E')
				put_img(w, h, *data, data->img_exit);
			else if (data->map_read[h][w] == 'P')
				put_player(w, h, data, data->player);
			w++;
		}
		w = 0;
		h++;
	}
	return (0);
}
