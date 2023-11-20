/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:40:19 by issierra          #+#    #+#             */
/*   Updated: 2023/11/20 12:14:49 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# include <stdio.h> //PARA PRINTF. BORRAR 

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_win;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel; //numero de bits usados para representar un pixel en la memoria
	int		line_length; //longitud de una linea de pixeles en bytes
	int		endian; //especifica el orden de los bytes de un pixel en la memoria
    int		img_width;
    int		img_height;
}				t_data;


# define BACKGROUND "./assets/background.xpm"

#endif