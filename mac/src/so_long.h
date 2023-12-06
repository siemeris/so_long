/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:40:19 by issierra          #+#    #+#             */
/*   Updated: 2023/12/06 09:10:55 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# include <fcntl.h>

typedef struct s_check_map {
	size_t		w;
	size_t		h;
	int			collect;
	int			exit;
	int			player;
	int			wall;
	char		**map_copy;
}				t_check_map;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		img_width;
	int		img_height;
	char	**map_read;
	size_t	map_width;
	size_t	map_height;
	int		player_x;
	int		player_y;
	int		moves;
	char	*img_path;
	int		collect;
	int		exit;
}				t_data;

# define BACKGROUND "./assets/grass5050.xpm"
# define WALL "./assets/tree50x50transparent.xpm"
# define EXIT "./assets/exit50x50.xpm"
# define PLAYER "./assets/merchant.xpm"
# define PLAYERL "./assets/merchant_L.xpm"
# define COLLECT "./assets/seta.xpm"
# define BUFFER 1000
# define IMG_WIDTH 50
# define IMG_HEIGHT 50
# define ESC 53
# define UP 126
# define W 13
# define DOWN 125
# define A 0
# define LEFT 123
# define S 1
# define RIGHT 124
# define D 2

int		close_window(t_data *prog);
char	**read_map(int fd, t_data *data);
int		check_map(t_data *data);
char	**check_file(char *file);
void	put_img(int x, int y, t_data data, char *path);
void	put_player(int x, int y, t_data *data);
int		key_hook(int keycode, t_data *prog);
int		ft_print_map(t_data *data);
int		go_up(t_data *prog);
int		go_down(t_data *prog);
int		go_right(t_data *prog);
int		go_left(t_data *prog);
void	run_window(t_data *data);
int		flood_fill(t_check_map *map, size_t x, size_t y);
void	free_map(char **map);
int		ft_print_error(int error);

#endif