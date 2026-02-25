/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:50:02 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/25 22:47:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @fn int *ft_range(int min, int max)
 * @brief Creates an array of integers containing a specific range.
 * @details Allocates memory for an array to hold all numbers from min
 * (included) to max (excluded). 
 * @param min The starting integer.
 * @param max The ending integer boundary.
 * @return A pointer to the allocated array, or NULL if min >= max or malloc
 * fails.
 */
int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = malloc (sizeof(int) * (max - min));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < (max - min))
		arr[i] = min + i;
	return (arr);
}
