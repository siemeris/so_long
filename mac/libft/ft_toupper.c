/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:52:10 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 11:39:42 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The toupper() function converts a lower-case letter to the corresponding 
// upper-case letter

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
