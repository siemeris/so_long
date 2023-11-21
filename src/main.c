/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:12:18 by issierra          #+#    #+#             */
/*   Updated: 2023/11/21 12:57:09 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"

//my_mlx_pixel_put es definida para poder pintar un pixel en la imagen

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(int keycode, t_data *prog)
{
	if (keycode == 53)
		mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	return (0);
}

int	key_hook(int keycode, t_data *prog)
{
	ft_printf("Hello from key_hook! %i %p %p \n", keycode, prog->mlx_ptr, prog->win_ptr);
	return (0);
}

//leemos la info del archivo. MEJORA: HACERLO CON GET_NEXT_LINE
char **read_map(int fd, t_data *data)
{
	int		numbytes;
	char	*buffer;


	buffer = (char *)ft_calloc(BUFFER + 1, sizeof(char));
	if (!buffer)
		return (0);
	ft_printf("Hello from read_map!\n");
	numbytes = read(fd, buffer ,BUFFER); 
	if (numbytes < 0)
	{
		ft_printf("Error al leer el archivo\n");
		free(buffer);
		return (0);
	}
	ft_printf("numbytes: %d\n", numbytes);
	ft_printf("buffer: %s\n", buffer);
	data->map_read = ft_split(buffer, '\n');
	// ft_printf("data->map_read: %s\n", data->map_read[0]);
	if (!data->map_read)
	{
		ft_printf("Error al leer el archivo\n");
		free(buffer);
		return (0);
	}
	// close(fd);
	return (data->map_read);
}

int check_map(t_data *data)
{
	data->map_height = 0;
	data->map_width = ft_strlen(data->map_read[0]);
	while (data->map_read[data->map_height])
	{
		if (ft_strlen(data->map_read[data->map_height]) != data->map_width)
		{
			ft_printf("Error\nMAPA INVALIDO\n");
			return (0);
		}
		data->map_height++;
	}
	ft_printf("MAPA VALIDO\n");
	return (1);
}

char **check_file(char *file)
{
	int		fd;
	t_data	data;
	// t_data	*data_ptr = NULL;

	ft_printf("Hello from check_file! %s\n", file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!read_map(fd, &data))
	 	return (0);
	// ft_printf("data.map_read en check file: %s\n", data.map_read[2]);
	close(fd);
	return (data.map_read);
}

void	put_img(int x, int y, t_data data, char *path)
{
	// int	img_w;
	// int	img_h;


	data.img = mlx_xpm_file_to_image(data.mlx_ptr, path, &data.img_width, &data.img_height);
	ft_printf ("img_width , img_height: %d, %d\n", data.img_width, data.img_height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, x * IMG_WIDTH, y * IMG_HEIGHT);

	// data->map->img = mlx_xpm_file_to_image(data->mlx, path, &img_w, &img_h);
	// mlx_put_image_to_window(data->mlx, data->win, data->map->img, \
	// (x * H_IMG), (y * W_IMG));


}


int	main(int argc, char **argv)
{
	// t_win	prog;
	t_data	data;

	//para las imagenes
	// int		img_width;
	// int		img_height;
	// char	*img_addr = "./assets/wooden.xpm";
	// void	*img_ptr;

	size_t		x;
	size_t		y;

	x = 0;
	y = 0;

	//COMPROBAMOS ARGUMENTOS
	if (argc != 2)
		return (ft_printf("Error\nINVALID ARGUMENT\n"));
	//ft_printf("data.map_read: %s\n", data.map_read[0]);
	
	//COMPROBAMOS MAPA
	data.map_read=check_file(argv[1]);
	if (!data.map_read)
		return (0);
	if (!check_map(&data))
	 	return (0);

	////CREAMOS MAPA CON LAS IMAGENES
	ft_printf("img.map_read: %s\n", data.map_read[0]);

	//CREAMOS LA VENTANA
	data.mlx_ptr = mlx_init(); //Inicilaizamos la miniLibX y guardamos el puntero en mlx 
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map_width * IMG_WIDTH, data.map_height * IMG_HEIGHT, "Hello world!"); //Creamos una ventana y guardamos el puntero en mlx_win
	ft_printf("data.map_width, data.map_height: %d, %d\n", data.map_width, data.map_height);
	//IMAGENES
	while (y < data.map_height)
	{
		while (x < data.map_width)
		{
			put_img(x, y, data, BACKGROUND);
			if (data.map_read[y][x] == '1')
			{
				ft_printf("map_read[y]: %s\n", data.map_read[y]);
				put_img(x, y, data, WALL);
				// ft_printf("WALL y x %i %i \n", y, x);
			}
			// else if (data.map_read[y][x] == 'C')
			// 	put_img(x, y, data, COLLECT);
			// else if (data.map_read[y][x] == 'E')
			// 	put_img(x, y, data, EXIT);
			// else if (data.map_read[y][x] == 'P')
			// 	put_player(x, y, data);
			x++;
		}
		x = 0;
		y++;
	}


	// data.img = mlx_xpm_file_to_image(data.mlx_ptr, BACKGROUND, &data.img_width, &data.img_height);
	// ft_printf ("BACKG img_width , img_height: %d, %d\n", data.img_width, data.img_height);
	// if (data.img == NULL)
	// 	ft_printf("Error al leer la imagen\n");
	// while (y < 300 )
	// {
	// 	x = 0;
	// 	while (x < 300)
	// 	{
	// 		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, x, y);
	// 		x++;
	// 	}
	// 	y++;
	// }
	// data.img = mlx_xpm_file_to_image(data.mlx_ptr, WALL, &data.img_width, &data.img_height);
	// ft_printf ("img_width , img_height: %d, %d\n", data.img_width, data.img_height);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 1 * data.img_height);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 2 * data.img_height);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 3 * data.img_height);
	
	//EVENTOS
	mlx_hook(data.win_ptr, 2, 1L<<0, close_window, &data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	// img.img = mlx_new_image(prog.mlx_ptr, 300, 300); //Creamos una imagen y guardamos el puntero en img.img
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian); //mlx_get_data_addr devuelve la direccion de memoria de la imagen
	// printf("bits_per_pixeel, line_length, endian: %d, %d, %d\n", img.bits_per_pixel, img.line_length, img.endian); //32 (4 bytes), 1200 (4bytes * 300), 0
	// my_mlx_pixel_put(&img, 5, 5, 0x00F6FC57); 
	// my_mlx_pixel_put(&img, 5, 10, 0x00F6FC57); 
	// my_mlx_pixel_put(&img, 10, 10, 0x00F6FC57); 
	// my_mlx_pixel_put(&img, 15, 15, 0x00F6FC57); 
	// mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, img.img, 0, 0);


	mlx_loop(data.mlx_ptr); //Renderizamos la ventana
}