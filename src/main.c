/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:12:18 by issierra          #+#    #+#             */
/*   Updated: 2023/11/20 09:44:51 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "../mlx/mlx.h"
#include <stdio.h> //ELIMINAR

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
}				t_data;

//my_mlx_pixel_put es definida para poder pintar un pixel en la imagen

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close(int keycode, t_win *prog)
{
	if (keycode == 53)
		mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	return (0);
}

int	main(void)
{
	// void	*mlx;
	// void	*mlx_win;
	t_win	prog;
	t_data	img;

	prog.mlx_ptr = mlx_init(); //Inicilaizamos la miniLibX y guardamos el puntero en mlx 
	prog.win_ptr = mlx_new_window(prog.mlx_ptr, 300, 300, "Hello world!"); //Creamos una ventana y guardamos el puntero en mlx_win
	mlx_hook(prog.win_ptr, 2, 1L<<0, close, &prog);
	img.img = mlx_new_image(prog.mlx_ptr, 300, 300); //Creamos una imagen y guardamos el puntero en img.img
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian); //mlx_get_data_addr devuelve la direccion de memoria de la imagen
	printf("bits_per_pixeel, line_length, endian: %d, %d, %d\n", img.bits_per_pixel, img.line_length, img.endian); //32 (4 bytes), 1200 (4bytes * 300), 0
	my_mlx_pixel_put(&img, 5, 5, 0x00F6FC57); 
	my_mlx_pixel_put(&img, 5, 10, 0x00F6FC57); 
	my_mlx_pixel_put(&img, 10, 10, 0x00F6FC57); 
	my_mlx_pixel_put(&img, 15, 15, 0x00F6FC57); 
	mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, img.img, 0, 0);
	mlx_loop(prog.mlx_ptr); //Renderizamos la ventana
}