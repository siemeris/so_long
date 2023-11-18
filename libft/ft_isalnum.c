/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:15:55 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 11:24:04 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isalnum() function tests for any character for which 
// isalpha(3) or isdigit(3) is true.
// The isalnum() function returns zero if the character tests false and returns 
// non-zero if the character tests true.

int	ft_isalnum(int c)
{
	if (('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z') || ('0' <= c && c <= '9'))
		return (1);
	return (0);
}
