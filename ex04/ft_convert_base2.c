/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:19:16 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/25 22:57:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @fn static int ft_strlen(char *str)
 * @brief Calculates string length for base validation inside the helper file.
 * @details Measures the length of the string until the null terminator.
 * @param str The string to measure.
 * @return The length of the string.
 */
static int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (str[++len] != '\0')
		len++;
	return (len);
}

/**
 * @fn int ft_digit_places(int nbr, char *base, int i)
 * @brief Pre-calculates the required string length to house the final number.
 * @details Safely prevents INT_MIN overflows by casting to long before div
 * math. Simulates the base conversion process just to count the required
 * characters.
 * @param nbr The base-10 integer to convert.
 * @param base The target custom alphabet.
 * @param i An initial counter (usually 0) to track the digits.
 * @return The exact number of characters required for the string allocation.
 */
int	ft_digit_places(int nbr, char *base, int i)
{
	long	n;
	int		size;

	size = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= size)
	{
		n /= size;
		i++;
	}
	i++;
	return (i);
}

/**
 * @fn void ft_putnbr_base(int nbr, char *base, char *conv)
 * @brief Converts and injects the final characters into the allocated string.
 * @details Divides the decimal integer by the target base length, mapping the 
 * remainders backwards into the previously allocated character array.
 * @param nbr The base-10 integer to convert.
 * @param base The target custom alphabet.
 * @param conv The pre-allocated string where characters will be injected.
 */
void	ft_putnbr_base(int nbr, char *base, char *conv)
{
	int		size;
	long	n;
	int		first;
	int		last;

	size = ft_strlen(base);
	last = ft_digit_places(nbr, base, 0);
	n = nbr;
	first = 0;
	if (n < 0)
	{
		*conv = '-';
		n *= -1;
		first++;
	}
	last--;
	while (n >= size)
	{
		conv[last] = base[n % size];
		n /= size;
		last--;
	}
	if (n < size)
		conv[first] = base[n];
}
