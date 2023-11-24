/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:04:17 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 11:27:34 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isprint() function tests for any printing character, including 
// space (` ')

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
