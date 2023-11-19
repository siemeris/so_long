/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:12:18 by issierra          #+#    #+#             */
/*   Updated: 2023/11/19 19:08:09 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "../mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init(); //Inicilaizamos la miniLibX y guardamos el puntero en mlx 
	mlx_win = mlx_new_window(mlx, 300, 300, "Hello world!"); //Creamos una ventana y guardamos el puntero en mlx_win
	img.img = mlx_new_image(mlx, 300, 300); //Creamos una imagen y guardamos el puntero en img.img
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian); //mlx_get_data_addr devuelve la direccion de memoria de la imagen
	my_mlx_pixel_put(&img, 5, 5, 0x00F6FC57); 
	my_mlx_pixel_put(&img, 5, 10, 0x00F6FC57); 
	my_mlx_pixel_put(&img, 10, 10, 0x00F6FC57); 
	my_mlx_pixel_put(&img, 15, 15, 0x00F6FC57); 
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx); //Renderizamos la ventana
}