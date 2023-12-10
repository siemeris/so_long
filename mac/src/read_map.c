/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:50:25 by issierra          #+#    #+#             */
/*   Updated: 2023/12/10 14:06:01 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_empty_lines(char *str)
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

static char	**free_buffer(char *buffer, int error)
{
	free(buffer);
	ft_print_error(error);
	return (0);
}

char	**read_map(int fd, t_data *data)
{
	int		numbytes;
	char	*buffer;

	buffer = (char *)ft_calloc(BUFFER + 1, sizeof(char));
	if (!buffer)
		return (0);
	numbytes = read(fd, buffer, BUFFER);
	if (numbytes <= 0)
		return (free_buffer(buffer, 8));
	if (!check_empty_lines(buffer))
		return (free_buffer(buffer, 9));
	data->map_read = ft_split(buffer, '\n');
	if (!data->map_read)
		return (free_buffer(buffer, 8));
	free(buffer);
	return (data->map_read);
}

char	**check_file(char *file)
{
	int		fd;
	t_data	data;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(11);
		return (0);
	}
	if (!read_map(fd, &data))
		return (0);
	close(fd);
	return (data.map_read);
}
