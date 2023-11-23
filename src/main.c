/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:12:18 by issierra          #+#    #+#             */
/*   Updated: 2023/11/23 11:52:33 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
#include "so_long.h"

int	close_window(int keycode, t_data *prog)
{
	if (keycode == 53)
	{
		mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
		//LIBERAMOS MEMORIA ---> MEJORAR
		// 9. Que no haya memory leaks
		// liberar todas las imagenes que he cargado, 
		//destruir la ventana 
		//y liberar el juego 
		// free(prog->mlx_ptr);
		// free(prog->win_ptr);
		// free(prog->img);
		// free(prog->map_read);
		exit (0);
	}
	return (0);
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

void	put_player(int x, int y, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, data->img_path, &data->img_width, &data->img_height);
	//ft_printf ("img_width , img_height: %d, %d\n", data.img_width, data.img_height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, x * IMG_WIDTH, y * IMG_HEIGHT);

	// data->map->img = mlx_xpm_file_to_image(data->mlx, path, &img_w, &img_h);
	// mlx_put_image_to_window(data->mlx, data->win, data->map->img, \
	// (x * H_IMG), (y * W_IMG));

	ft_printf("player_x, player_y en put_player: %d, %d\n", data->player_x, data->player_y);
}

int	key_hook(int keycode, t_data *prog)
{
	ft_printf("Hello from key_hook! %i %p %p \n", keycode, prog->mlx_ptr, prog->win_ptr);
	ft_printf("player_x, player_y en key_hook: %d, %d\n", prog->player_x, prog->player_y);

	// if (keycode == ESC)
	// 	close_window(prog);
	if (keycode == UP || keycode == W)
		go_up(prog);
	if (keycode == DOWN || keycode == A)
	 	go_down(prog);
	if (keycode == RIGHT || keycode == D)
	 	go_right(prog);
	if (keycode == LEFT || keycode == S)
	 	go_left(prog);
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
			 	put_player(w, h, data);
			}
			w++;
		}
		w = 0;
		h++;
	}
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
	// 7. Número de argumentos
	// 8. Que la extensión del archivo del mapa sea .ber 
	if (argc != 2 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
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

	//INICIALIZAMOS CONTADOR DE MOVIMIENTOS, PLAYER y EXIT
	data.moves = 0;
	data.img_path = PLAYER;
	data.exit = 0;
	//CREAMOS LA VENTANA
	// data.mlx_ptr = mlx_init(); //Inicilaizamos la miniLibX y guardamos el puntero en mlx 
	// data.win_ptr = mlx_new_window(data.mlx_ptr, data.map_width * IMG_WIDTH, data.map_height * IMG_HEIGHT, "Hello world!"); //Creamos una ventana y guardamos el puntero en mlx_win
	//ft_printf("data.map_width, data.map_height: %d, %d\n", data.map_width, data.map_height);
	run_window(&data);

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