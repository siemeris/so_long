/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:40:19 by issierra          #+#    #+#             */
/*   Updated: 2023/11/22 12:06:14 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

// # include <stdio.h> //PARA PRINTF. BORRAR 
#include <fcntl.h> //PARA OPEN. BORRAR

// typedef struct s_win
// {
// 	void	*mlx_ptr; //puntero a la conexion con el servidor grafico
// 	void	*win_ptr; //puntero a la ventana
// }		t_win;

typedef struct	s_check_map {
    size_t		w;
	size_t		h;
	int			collect;
	int			exit;
	int			player;
	int			wall;
}				t_check_map;

typedef struct	s_data {
    void	*mlx_ptr; //puntero a la conexion con el servidor grafico
    void	*win_ptr; //puntero a la ventana
	void	*img; //puntero a la imagen
	char	*addr; //puntero al primer byte de la imagen en la memoria
	int		bits_per_pixel; //numero de bits usados para representar un pixel en la memoria
	int		line_length; //longitud de una linea de pixeles en bytes
	int		endian; //especifica el orden de los bytes de un pixel en la memoria
    int		img_width; //ancho de la imagen
    int		img_height; //alto de la imagen
    char    **map_read; //mapa leido del fichero
    size_t  map_width; //ancho del mapa
    size_t  map_height; //alto del mapa
    int     player_x; //posicion x del jugador
    int     player_y; //posicion y del jugador
    int     moves; //numero de movimientos del jugador
    char   *img_path; //ruta de la imagen
}				t_data;


# define BACKGROUND "./assets/grass5050.xpm"
# define WALL "./assets/tree50x50transparent.xpm"
# define EXIT "./assets/exit50x50.xpm"
# define PLAYER "./assets/merchant.xpm"
# define PLAYERL "./assets/merchantL.xpm"
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

int	close_window(int keycode, t_data *prog);
char **read_map(int fd, t_data *data);
int check_map(t_data *data);
char **check_file(char *file);
void	put_img(int x, int y, t_data data, char *path);
void	put_player(int x, int y, t_data data, char *path);
int	key_hook(int keycode, t_data *prog);
int	ft_print_map(t_data *data);
int	go_up(t_data *prog);
int	go_down(t_data *prog);
int	go_right(t_data *prog);
int	go_left(t_data *prog);
void run_window(t_data *data);

#endif