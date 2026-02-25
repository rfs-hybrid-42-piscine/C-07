/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:00:08 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/25 22:54:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @fn static int ft_strlen(char *str)
 * @brief Calculates the length of a string.
 * @details Iterates through the character array until it hits the null byte.
 * @param str The string to measure.
 * @return The number of characters in the string.
 */
static int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

/**
 * @fn static int ft_joinlen(int size, char **strs, char *sep)
 * @brief Computes the total memory size required for the joined string.
 * @details Sums the lengths of all strings in the array and adds the length 
 * of the separator multiplied by the number of gaps between strings.
 * @param size The number of strings in the array.
 * @param strs The array of strings to be joined.
 * @param sep The separator string.
 * @return The total combined length required (excluding the null terminator).
 */
static int	ft_joinlen(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (++i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += ft_strlen(sep);
	}
	return (len);
}

/**
 * @fn static char *ft_strcat(char *dest, char *src)
 * @brief Appends the source string to the end of the destination string.
 * @details Finds the null terminator of the destination string and overwrites 
 * it with the characters from the source, guaranteeing a new null terminator.
 * @param dest The string to append to.
 * @param src The string to append from.
 * @return A pointer to the modified destination string.
 */
static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = -1;
	while (dest[++i])
		;
	j = -1;
	while (src[++j])
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}

/**
 * @fn char *ft_strjoin(int size, char **strs, char *sep)
 * @brief Concatenates an array of strings separated by a specific string.
 * @details Dynamically allocates exactly enough memory for the combined strings
 * plus separators. If size is 0, safely returns an empty heap-allocated string.
 * @param size The number of strings in the array.
 * @param strs The array of strings to join.
 * @param sep The string to interleave between the elements.
 * @return The final joined string, or NULL if malloc fails.
 */
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		len;
	int		i;

	len = ft_joinlen(size, strs, sep);
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	*joined = '\0';
	if (size > 0)
	{
		i = -1;
		while (++i < size)
		{
			ft_strcat(joined, strs[i]);
			if (i < size - 1)
				ft_strcat(joined, sep);
		}
		joined[len] = '\0';
	}
	return (joined);
}
