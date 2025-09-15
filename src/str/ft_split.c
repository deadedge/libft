/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:45:29 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_spaces(char **space)
{
	unsigned int	i;

	i = 0;
	while (space[i])
	{
		free(space[i]);
		i++;
	}
	free(space);
	return ;
}

int	calculate_split(char const *s, char c, unsigned int s_len)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (i < s_len)
	{
		while (i < s_len && s[i] == c)
			i++;
		if (i < s_len && s[i] != c)
		{
			count++;
			while (i < s_len && s[i] != c)
				i++;
		}
	}
	return (count);
}

void	*fill_space(char *space, const char *s, int *last_index, char c)
{
	int	start;
	int	len;
	int	i;

	start = *last_index;
	len = 0;
	i = 0;
	while (s[start] == c)
		start++;
	while (s[start + len] && s[start + len] != c)
		len++;
	space = malloc(sizeof(char) * (len + 1));
	if (!space)
		return (NULL);
	while (i < len)
	{
		space[i] = s[start + i];
		i++;
	}
	space[len] = '\0';
	*last_index = start + len + 1;
	return (space);
}

void	fill(char **result, int split_count, char const *s, char c)
{
	int	i;
	int	last_index;

	last_index = 0;
	i = 0;
	while (i < split_count)
	{
		result[i] = fill_space(result[i], s, &last_index, c);
		if (result[i] == NULL)
		{
			free_spaces(result);
			break ;
		}
		i++;
	}
	result[i] = NULL;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char			**array_b;
	unsigned int	s_len;
	int				split_count;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	split_count = calculate_split(s, c, s_len);
	array_b = malloc(sizeof(char *) * (split_count + 1));
	if (!array_b)
		return (NULL);
	fill(array_b, split_count, s, c);
	return (array_b);
}

// int	main(void)
// {
// 	int		i;
// 	char	**teste;

// 	i = 0;
// 	teste = ft_split("teste", 'e');
// 	while (teste[i])
// 	{
// 		printf("%s\n", teste[i]);
// 		i++;
// 	}
// 	freeSpaces(teste);
// 	return (0);
// }
