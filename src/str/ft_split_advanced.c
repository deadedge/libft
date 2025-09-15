/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_advanced.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:45:29 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_next_quote(char const *str, int start, int str_len,
		int actual_state)
{
	int	i;

	i = 0;
	if (actual_state)
		return (1);
	while (str[start + i] && start + i < str_len)
	{
		if (str[start + i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

static void	free_spaces(char **space)
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

static int	count_words(char const *str, char c)
{
	int	i;
	int	str_len;
	int	count;
	int	inside_str;

	i = 0;
	count = 0;
	str_len = ft_strlen(str);
	inside_str = 0;
	while (str[i] == c)
		i++;
	while (i < str_len)
	{
		if (str[i] == '\'' && find_next_quote(str, (i + 1), str_len,
				inside_str))
			inside_str = !inside_str;
		if ((str[i] == c && (i + 1 != str_len)) && !inside_str)
			count++;
		i++;
	}
	return (count + 1);
}

static int	fill_line(char const *str, char **line_to_fill, int *last_index,
		char delimiter)
{
	int	start;
	int	len;
	int	inside_str;

	start = *last_index;
	len = 0;
	inside_str = 0;
	while (str[start] == delimiter)
		start++;
	while (str[start + len])
	{
		if (str[start + len] == '\'' && find_next_quote(str, start + len + 1,
				ft_strlen(str), inside_str))
			inside_str = !inside_str;
		if (str[start + len] == delimiter && !inside_str)
			break ;
		len++;
	}
	*line_to_fill = malloc(sizeof(char) * (len + 1));
	if (!*line_to_fill)
		return (0);
	ft_strlcpy(*line_to_fill, str + start, len + 1);
	*last_index = start + len + 1;
	return (1);
}

char	**ft_split_advanced(char const *s, char c)
{
	char	**result;
	int		words_number;
	int		i;
	int		index;

	if (!s)
		return (NULL);
	i = 0;
	index = 0;
	words_number = count_words(s, c);
	result = malloc(sizeof(char *) * (words_number + 1));
	if (!result)
		return (NULL);
	while (i < words_number)
	{
		if (!fill_line(s, &result[i], &index, c))
		{
			free_spaces(result);
			break ;
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
