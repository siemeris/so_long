/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:16:40 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 11:25:25 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isascii() function tests for an ASCII character, which is any character 
// between 0 and octal 0177 inclusive.

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
