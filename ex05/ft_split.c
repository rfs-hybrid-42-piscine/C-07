/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:40:00 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/26 01:51:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

/**
 * @fn static char **free_split(char **split, size_t i)
 * @brief Safeguard memory manager to prevent leaks during massive allocations.
 * @details If any internal string malloc fails, this iterates backwards to free
 * all previously successful allocations before destroying the main array.
 * @param split The main array containing string pointers.
 * @param i The index where the malloc failure occurred.
 * @return NULL consistently to terminate the calling function gracefully.
 */
static char	**free_split(char **split, size_t i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
	return (NULL);
}

/**
 * @fn static bool found_char(char c, char *charset)
 * @brief Checks if a character matches any inside the separator charset.
 * @details Scans the separator string to see if the given character is a
 * delimiter.
 * @param c The character being tested.
 * @param charset The string containing all delimiter characters.
 * @return true if the character is a delimiter, false otherwise.
 */
static bool	found_char(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (true);
	return (false);
}

/**
 * @fn static size_t count_words(char *str, char *charset)
 * @brief Iterates the string to count distinct word blocks for initial malloc.
 * @details Uses a boolean flag to track transitions between delimiters and
 * words.
 * @param str The string being parsed.
 * @param charset The string containing all delimiter characters.
 * @return The total number of valid words separated by delimiters.
 */
static size_t	count_words(char *str, char *charset)
{
	size_t	word_count;
	bool	in_word;

	word_count = 0;
	in_word = false;
	while (*str)
	{
		if (!found_char(*str, charset) && !in_word)
		{
			in_word = true;
			word_count++;
		}
		else if (found_char(*str, charset))
			in_word = false;
		str++;
	}
	return (word_count);
}

/**
 * @fn static char *get_next_word(char **str, char *charset)
 * @brief Isolates, allocates, and returns the next valid word from the string.
 * @details Modifies the root string pointer dynamically to advance past 
 * parsed tokens, allowing continuous extraction across multiple function calls.
 * @param str A double pointer to the current position in the main string.
 * @param charset The string containing all delimiter characters.
 * @return A dynamically allocated string containing the isolated word, or NULL.
 */
static char	*get_next_word(char **str, char *charset)
{
	char	*word;
	size_t	len;
	size_t	i;

	while (found_char(**str, charset))
		(*str)++;
	len = 0;
	while ((*str)[len] && !found_char((*str)[len], charset))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = (*str)[i];
		i++;
	}
	word[len] = '\0';
	*str += len;
	return (word);
}

/**
 * @fn char **ft_split(char *str, char *charset)
 * @brief Splits a string into an array of smaller strings based on separators.
 * @details Allocates a parent array of pointers based on word count, then
 * iterates to allocate and inject each individual word into the array.
 * @param str The main string to be split.
 * @param charset A string containing all characters acting as delimiters.
 * @return A null-terminated array of strings, or NULL on error.
 */
char	**ft_split(char *str, char *charset)
{
	char	**split;
	size_t	word_count;
	size_t	i;

	if (!str || !charset)
		return (NULL);
	word_count = count_words(str, charset);
	split = malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		split[i] = get_next_word(&str, charset);
		if (!split[i])
			return (free_split(split, i));
		i++;
	}
	split[word_count] = NULL;
	return (split);
}
