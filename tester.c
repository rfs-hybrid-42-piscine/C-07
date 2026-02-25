/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:03:45 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/25 23:03:49 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* --- Master Switch --- */
#ifdef TEST_ALL
# define EX00
# define EX01
# define EX02
# define EX03
# define EX04
# define EX05
#endif

/* --- Prototypes --- */
char	*ft_strdup(char *src);
int		*ft_range(int min, int max);
int		ft_ultimate_range(int **range, int min, int max);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	**ft_split(char *str, char *charset);

/* --- Main Testing Function --- */
int	main(void)
{
#ifdef EX00
	{
		printf("--- EX00: ft_strdup ---\n");
		char *dup1 = ft_strdup("Hello 42!");
		char *dup2 = ft_strdup("");
		printf("Original: 'Hello 42!' | Duplicated: '%s'\n", dup1);
		printf("Original: ''          | Duplicated: '%s'\n\n", dup2);
		free(dup1);
		free(dup2);
	}
#endif

#ifdef EX01
	{
		printf("--- EX01: ft_range ---\n");
		int *arr1 = ft_range(5, 10);
		int *arr2 = ft_range(10, 5);
		printf("Range 5 to 10: ");
		if (arr1)
		{
			for (int i = 0; i < 5; i++)
				printf("%d ", arr1[i]);
			printf("\n");
			free(arr1);
		}
		printf("Range 10 to 5: %p (Expected: nil or 0x0)\n\n", (void *)arr2);
	}
#endif

#ifdef EX02
	{
		printf("--- EX02: ft_ultimate_range ---\n");
		int *arr3 = NULL;
		int size = ft_ultimate_range(&arr3, 5, 10);
		printf("Size returned: %d (Expected: 5)\n", size);
		printf("Range 5 to 10: ");
		if (arr3)
		{
			for (int i = 0; i < size; i++)
				printf("%d ", arr3[i]);
			printf("\n");
			free(arr3);
		}
		printf("\n");
	}
#endif

#ifdef EX03
	{
		printf("--- EX03: ft_strjoin ---\n");
		char *strs[] = {"Hello", "world", "from", "42"};
		char *joined = ft_strjoin(4, strs, " | ");
		char *joined_zero = ft_strjoin(0, strs, " | ");
		printf("Joined (size 4): %s\n", joined);
		printf("Joined (size 0): '%s'\n\n", joined_zero);
		free(joined);
		free(joined_zero);
	}
#endif

#ifdef EX04
	{
		printf("--- EX04: ft_convert_base ---\n");
		char *conv1 = ft_convert_base("42", "0123456789", "01");
		char *conv2 = ft_convert_base("   -+-101010", "01", "0123456789ABCDEF");
		char *conv3 = ft_convert_base("42", "0123+4", "01"); /* Invalid base */
		printf("42 from Dec to Bin       : %s (Expected: 101010)\n", conv1);
		printf("-101010 from Bin to Hex  : %s (Expected: -2A)\n", conv2);
		printf("Invalid base translation : %p (Expected: nil or 0x0)\n\n", (void *)conv3);
		free(conv1);
		free(conv2);
		free(conv3);
	}
#endif

#ifdef EX05
	{
		printf("--- EX05: ft_split ---\n");
		char **split = ft_split("Hello,,World! , 42Piscine", ", ");
		printf("Splitting 'Hello,,World! , 42Piscine' by ', ':\n");
		if (split)
		{
			for (int i = 0; split[i] != NULL; i++)
			{
				printf("Word %d: %s\n", i, split[i]);
				free(split[i]);
			}
			free(split);
		}
		printf("\n");
	}
#endif

	return (0);
}
