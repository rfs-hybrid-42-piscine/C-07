/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:25:41 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/25 22:59:42 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @fn int ft_ultimate_range(int **range, int min, int max)
 * @brief Allocates and assigns an array of integers using a double pointer.
 * @details Calculates the necessary memory block size and uses a double pointer
 * to directly modify the calling function's array pointer. If the range is 
 * invalid (min >= max), it safely sets the pointer to NULL.
 * @param range A pointer to the array pointer that will hold the sequence.
 * @param min The starting integer.
 * @param max The ending integer boundary.
 * @return The size of the range, 0 if min >= max, or -1 on allocation failure.
 */
int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc (sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	i = -1;
	while (++i < (max - min))
		(*range)[i] = min + i;
	return (max - min);
}
