/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:19:08 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/25 22:56:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

int		ft_digit_places(int nbr, char *base, int i);
void	ft_putnbr_base(int nbr, char *base, char *conv);

/**
 * @fn static int ft_is_base_valid(char *base)
 * @brief Validates the custom base alphabet for atoi processing.
 * @details Ensures no duplicates, no mathematical signs, and NO whitespaces.
 * @param base The string representing the mathematical base.
 * @return true if valid, false if invalid.
 */
static bool	ft_is_base_valid(char *base)
{
	int	i;
	int	j;

	if (!base[0] || !base[1])
		return (false);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= '\t' && base[i] <= '\r'))
			return (false);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (false);
	}
	return (true);
}

/**
 * @fn static int ft_get_base_index(char c, char *base)
 * @brief Finds the mathematical value of a character within the custom base.
 * @details Iterates through the valid base string to locate the exact index
 * of the provided character, mapping its integer value.
 * @param c The character to search for.
 * @param base The custom alphabet string.
 * @return The index of the character, or -1 if the character is not in the
 * base.
 */
static int	ft_get_base_index(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (-1);
}

/**
 * @fn static int ft_atoi_base(char *str, char *base)
 * @brief Converts a string in a custom base into a standard integer.
 * @details Parses leading whitespaces and signs. Accumulates the value of valid
 * base characters until an unrecognized character is encountered.
 * @param str The string to parse.
 * @param base The custom alphabet string.
 * @return The evaluated base-10 integer.
 */
static int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	index;
	int	base_len;

	if (!ft_is_base_valid(base))
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str)
	{
		index = ft_get_base_index(*str++, base);
		if (index == -1)
			break ;
		result = result * base_len + index;
	}
	return (result * sign);
}

/**
 * @fn char *ft_convert_base(char *nbr, char *base_from, char *base_to)
 * @brief Orchestrates the translation of a number string between two bases.
 * @details Acts as the main pipeline: converts the initial string to decimal, 
 * calculates required memory for the new base, allocates it, and translates it.
 * @param nbr The mathematical string to translate.
 * @param base_from The alphabet the string is currently written in.
 * @param base_to The alphabet to translate the string into.
 * @return The newly allocated translated string, or NULL if bases are invalid.
 */
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*conv;
	int		dec;
	int		i;

	if (!ft_is_base_valid(base_from) || !ft_is_base_valid(base_to))
		return (NULL);
	dec = ft_atoi_base(nbr, base_from);
	i = ft_digit_places(dec, base_to, 0);
	conv = malloc(sizeof(char) * (i + 1));
	if (!conv)
		return (NULL);
	ft_putnbr_base(dec, base_to, conv);
	conv[i] = '\0';
	return (conv);
}
