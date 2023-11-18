/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:40:08 by issierra          #+#    #+#             */
/*   Updated: 2023/09/28 09:19:31 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The function ft_isalpha() returns a non-zero value if the character passed 
// as an argument is an alphabetic character.

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}
