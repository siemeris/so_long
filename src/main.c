/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:12:18 by issierra          #+#    #+#             */
/*   Updated: 2023/11/22 10:25:56 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"

int	close_window(int keycode, t_data *prog)
{
	if (keycode == 53)
		mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
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

	// SE DEBE COMPROBAR:
	// 1. Que el mapa sea rectangular
	// 2. Que el mapa tenga al menos un coleccionable (C)
	// 3. Que el mapa tenga al menos una salida (E)
	// 4. Que el mapa tenga al menos un jugador (P)
	// 5. Que el mapa tenga al menos un muro alrededor (1)
	// 6. Que el mapa tenga al menos un camino válido (0)

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
	data.img = mlx_xpm_file_to_image(data.mlx_ptr, path, &data.img_width, &data.img_height);
	//ft_printf ("img_width , img_height: %d, %d\n", data.img_width, data.img_height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, x * IMG_WIDTH, y * IMG_HEIGHT);

	// data->map->img = mlx_xpm_file_to_image(data->mlx, path, &img_w, &img_h);
	// mlx_put_image_to_window(data->mlx, data->win, data->map->img, \
	// (x * H_IMG), (y * W_IMG));
}

void	put_player(int x, int y, t_data data, char *path)
{
	data.img = mlx_xpm_file_to_image(data.mlx_ptr, path, &data.img_width, &data.img_height);
	//ft_printf ("img_width , img_height: %d, %d\n", data.img_width, data.img_height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, x * IMG_WIDTH, y * IMG_HEIGHT);

	// data->map->img = mlx_xpm_file_to_image(data->mlx, path, &img_w, &img_h);
	// mlx_put_image_to_window(data->mlx, data->win, data->map->img, \
	// (x * H_IMG), (y * W_IMG));

	ft_printf("player_x, player_y en put_player: %d, %d\n", data.player_x, data.player_y);
}

int	key_hook(int keycode, t_data *prog)
{
	ft_printf("Hello from key_hook! %i %p %p \n", keycode, prog->mlx_ptr, prog->win_ptr);
	ft_printf("player_x, player_y en key_hook: %d, %d\n", prog->player_x, prog->player_y);

	// if (keycode == ESC)
	// 	close_window(prog);
	if (keycode == UP || keycode == W)
		go_up(prog);
	// if (keycode == DOWN || keycode == A)
	// 	go_down(prog);
	// if (keycode == RIGHT || keycode == D)
	// 	go_right(prog);
	// if (keycode == LEFT || keycode == S)
	// 	go_left(prog);
	return (0);
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
			{
				put_img(w, h, *data, WALL);
				// ft_printf("WALL y x %i %i \n", y, x);
			}
			else if (data->map_read[h][w] == 'C')
			 	put_img(w, h, *data, COLLECT);
			else if (data->map_read[h][w] == 'E')
			 	put_img(w, h, *data, EXIT);
			else if (data->map_read[h][w] == 'P')
			{
				//Tenemos que guardar la posicion del jugador
				data->player_x = w;
				data->player_y = h;
				ft_printf("player_x, player_y en print map: %d, %d\n", data->player_x, data->player_y);
			 	put_player(w, h, *data, PLAYER);
			}
			w++;
		}
		w = 0;
		h++;
	}
	return (0);
}

int	go_up(t_data *prog)
{
	prog->moves++;
	ft_printf("Hello from go_up! moves %i %p %p \n", prog->moves, prog->mlx_ptr, prog->win_ptr);
	ft_printf("player_x, player_y en go_up: %d, %d\n", prog->player_x, prog->player_y);
	
	prog->map_read[prog->player_y][prog->player_x] = '0';
	prog->map_read[prog->player_y - 1][prog->player_x] = 'P';
	prog->player_y--;
	ft_print_map(prog);

	return (0);
}

void run_window(t_data *data)
{
	data->mlx_ptr = mlx_init(); //Inicilaizamos la miniLibX y guardamos el puntero en mlx 
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_width * IMG_WIDTH, data->map_height * IMG_HEIGHT, "Hello world!"); //Creamos una ventana y guardamos el puntero en mlx_win
	ft_printf("data.map_width, data.map_height: %d, %d\n", data->map_width, data->map_height);
	ft_print_map(data);
	//EVENTOS
	mlx_key_hook(data->win_ptr, key_hook, data); //Llamamos a la funcion key_hook cuando se pulse una tecla
	mlx_hook(data->win_ptr, 2, 1L<<0, close_window, data); //Llamamos a la funcion close_window cuando se pulse la tecla ESC

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

	// size_t		w;
	// size_t		h;

	// w = 0;
	// h = 0;

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
	// data.mlx_ptr = mlx_init(); //Inicilaizamos la miniLibX y guardamos el puntero en mlx 
	// data.win_ptr = mlx_new_window(data.mlx_ptr, data.map_width * IMG_WIDTH, data.map_height * IMG_HEIGHT, "Hello world!"); //Creamos una ventana y guardamos el puntero en mlx_win
	//ft_printf("data.map_width, data.map_height: %d, %d\n", data.map_width, data.map_height);
	run_window(&data);

	//INICIALIZAMOS CONTADOR DE MOVIMIENTOS
	data.moves = 0;

	//IMAGENES
	// while (h < data.map_height)
	// {
	// 	while (w < data.map_width)
	// 	{
	// 		put_img(w, h, data, BACKGROUND);
	// 		if (data.map_read[h][w] == '1')
	// 		{
	// 			put_img(w, h, data, WALL);
	// 			// ft_printf("WALL y x %i %i \n", y, x);
	// 		}
	// 		else if (data.map_read[h][w] == 'C')
	// 		 	put_img(w, h, data, COLLECT);
	// 		else if (data.map_read[h][w] == 'E')
	// 		 	put_img(w, h, data, EXIT);
	// 		else if (data.map_read[h][w] == 'P')
	// 		{
	// 			//Tenemos que guardar la posicion del jugador
	// 			data.player_x = w;
	// 			data.player_y = h;
	// 			ft_printf("player_x, player_y en main: %d, %d\n", data.player_x, data.player_y);
	// 		 	put_player(w, h, data, PLAYER);
	// 		}
	// 		w++;
	// 	}
	// 	w = 0;
	// 	h++;
	// }



	//RENDERIZAMOS LA VENTANA
	mlx_loop(data.mlx_ptr); //Renderizamos la ventana
}