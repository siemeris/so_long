/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars_monster.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:24:16 by issierra          #+#    #+#             */
/*   Updated: 2023/12/06 10:24:26 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_chars_monster(t_check_map *check, t_data *data)
{
	check->monster++;
	data->monster_x = check->w;
	data->monster_y = check->h;
	if (check->monster > 1)
		return (ft_print_error(8));
	return (1);
}
