/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:51:28 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	contains(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] && c)
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

int	count_final(char const *s1, char const *set, unsigned int strlen)
{
	unsigned int	i;
	unsigned int	count;

	i = strlen - 1;
	count = 0;
	while (s1[i] && contains(s1[i], set) && (i - 1) > 0)
	{
		count++;
		i--;
	}
	return (count);
}

unsigned int	invert_number(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

char	*do_trim(unsigned int start, unsigned int final, unsigned int s1_len,
		char const *s1)
{
	unsigned int	i;
	unsigned int	j;
	char			*result;

	i = start;
	j = 0;
	if (start + final > s1_len)
		return (ft_strdup(""));
	result = malloc(sizeof * s1 * ((s1_len + 1) - invert_number((start
						+ final))));
	if (!result)
		return (NULL);
	while (j < (s1_len - invert_number((start + final))))
		result[j++] = s1[i++];
	result[(s1_len)-invert_number((start + final))] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	s1_len;
	unsigned int	start;
	unsigned int	final;

	if (!s1)
		return (NULL);
	if (!s1[0])
		return (ft_strdup(""));
	start = 0;
	while (s1[start] && contains(s1[start], set))
		start++;
	s1_len = ft_strlen(s1);
	final = count_final(s1, set, s1_len);
	return (do_trim(start, final, s1_len, s1));
}

// int	main(void)
// {
// 	char *a = ft_strtrim("   xxxtripouille   xxx", " x");
// 	printf("%s\n", a);
// 	free(a);

// 	return (0);
// }