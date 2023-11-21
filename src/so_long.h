/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:40:19 by issierra          #+#    #+#             */
/*   Updated: 2023/11/21 10:03:03 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

// # include <stdio.h> //PARA PRINTF. BORRAR 
#include <fcntl.h> //PARA OPEN. BORRAR

typedef struct s_win
{
	void	*mlx_ptr; //puntero a la conexion con el servidor grafico
	void	*win_ptr; //puntero a la ventana
}		t_win;

typedef struct	s_data {
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
}				t_data;


# define BACKGROUND "./assets/background.xpm"
# define WALL "./assets/wooden.xpm"
# define BUFFER 1000


#endif