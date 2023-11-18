/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issierra <issierra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:16:46 by issierra          #+#    #+#             */
/*   Updated: 2023/09/28 09:33:54 by issierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  Return zero if the character tests false and return non-zero if the 
//  character tests true.

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
