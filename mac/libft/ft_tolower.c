/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:52:23 by issierra          #+#    #+#             */
/*   Updated: 2023/09/29 11:39:20 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The tolower() function converts an upper-case letter to the corresponding 
// lower-case letter.

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
