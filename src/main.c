/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:12:18 by issierra          #+#    #+#             */
/*   Updated: 2023/11/21 09:44:36 by issierra         ###   ########.fr       */
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

int	close_window(int keycode, t_win *prog)
{
	if (keycode == 53)
		mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	return (0);
}

int	key_hook(int keycode, t_win *prog)
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
	int		i;
	size_t		len;

	i = 0;
	len = ft_strlen(data->map_read[0]);
	while (data->map_read[i])
	{
		if (ft_strlen(data->map_read[i]) != len)
		{
			ft_printf("Error\nMAPA INVALIDO\n");
			return (0);
		}
		i++;
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

int	main(int argc, char **argv)
{
	t_win	prog;
	t_data	img;

	//para las imagenes
	// int		img_width;
	// int		img_height;
	// char	*img_addr = "./assets/wooden.xpm";
	// void	*img_ptr;

	int		x;
	int		y;

	x = 0;
	y = 0;

	//COMPROBAMOS ARGUMENTOS
	if (argc != 2)
		return (ft_printf("Error\nINVALID ARGUMENT\n"));
	//ft_printf("data.map_read: %s\n", data.map_read[0]);
	//COMPROBAMOS MAPA
	img.map_read=check_file(argv[1]);
	if (!img.map_read)
		return (0);
	check_map(&img);

	//CREAMOS MAPA CON LAS IMAGENES
	ft_printf("img.map_read: %s\n", img.map_read[0]);
	// if (!check_map(&data))
	// 	return (0);

	
	//CREAMOS LA VENTANA
	prog.mlx_ptr = mlx_init(); //Inicilaizamos la miniLibX y guardamos el puntero en mlx 
	prog.win_ptr = mlx_new_window(prog.mlx_ptr, 300, 300, "Hello world!"); //Creamos una ventana y guardamos el puntero en mlx_win
	
	//EVENTOS
	mlx_hook(prog.win_ptr, 2, 1L<<0, close_window, &prog);
	mlx_key_hook(prog.win_ptr, key_hook, &prog);
	// img.img = mlx_new_image(prog.mlx_ptr, 300, 300); //Creamos una imagen y guardamos el puntero en img.img
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian); //mlx_get_data_addr devuelve la direccion de memoria de la imagen
	// printf("bits_per_pixeel, line_length, endian: %d, %d, %d\n", img.bits_per_pixel, img.line_length, img.endian); //32 (4 bytes), 1200 (4bytes * 300), 0
	// my_mlx_pixel_put(&img, 5, 5, 0x00F6FC57); 
	// my_mlx_pixel_put(&img, 5, 10, 0x00F6FC57); 
	// my_mlx_pixel_put(&img, 10, 10, 0x00F6FC57); 
	// my_mlx_pixel_put(&img, 15, 15, 0x00F6FC57); 
	// mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, img.img, 0, 0);

	//IMAGENES
	img.img = mlx_xpm_file_to_image(prog.mlx_ptr, BACKGROUND, &img.img_width, &img.img_height);
	if (img.img == NULL)
		ft_printf("Error al leer la imagen\n");
	while (y < 300 )
	{
		x = 0;
		while (x < 300)
		{
			mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, img.img, x, y);
			x++;
		}
		y++;
	}
	img.img = mlx_xpm_file_to_image(prog.mlx_ptr, WALL, &img.img_width, &img.img_height);
	ft_printf ("img_width, img_height: %d, %d\n", img.img_width, img.img_height);
	mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, img.img, 0, 0);
	mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, img.img, 0, 1 * img.img_height);
	mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, img.img, 0, 2 * img.img_height);
	mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, img.img, 0, 3 * img.img_height);
	

	mlx_loop(prog.mlx_ptr); //Renderizamos la ventana
}