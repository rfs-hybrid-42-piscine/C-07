/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:34:52 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/25 22:47:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @fn char *ft_strdup(char *src)
 * @brief Duplicates a string using dynamic memory allocation.
 * @details Calculates the length of the source string, allocates enough memory 
 * on the heap to store it (including the null terminator), and copies it over.
 * @param src The string to duplicate.
 * @return A pointer to the newly allocated string, or NULL if malloc fails.
 */
char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	if (!src)
		return (NULL);
	len = -1;
	while (src[++len])
		;
	dup = malloc (sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < len)
		dup[i] = src[i];
	dup[len] = '\0';
	return (dup);
}
