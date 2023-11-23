/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:50:25 by issierra          #+#    #+#             */
/*   Updated: 2023/11/23 11:51:26 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int check_empty_lines(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			j++;
			if (str[i + 1] == '\n')
				return (0);
		}
		i++;
	}
	return (1);
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
	ft_printf("buffer: %s", buffer);
	//comprobamos que no haya líneas en blanco
	if (!check_empty_lines(buffer))
	{
		ft_printf("Error\nMAPA NO VÁLIDO. EMPTY LINES\n");
		free(buffer);
		return (0);
	}
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
