/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_advanced.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:45:29 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/28 23:49:09 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_quote(char c, char *quote)
{
	if (c == '\'' || c == '"')
	{
		if (*quote == 0)
			*quote = c;
		else if (*quote == c)
			*quote = 0;
	}
}

static int	count_words(char const *str, char c)
{
	int		i;
	int		count;
	char	quote;

	i = 0;
	count = 0;
	quote = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		count++;
		while (str[i])
		{
			handle_quote(str[i], &quote);
			if (str[i] == c && quote == 0)
				break ;
			i++;
		}
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static int	calculate_word_len(char const *str, int start, char delimiter)
{
	int		len;
	char	quote;

	len = 0;
	quote = 0;
	while (str[start + len])
	{
		if (str[start + len] == '\'' || str[start + len] == '"')
		{
			if (quote == 0)
				quote = str[start + len];
			else if (quote == str[start + len])
				quote = 0;
		}
		if (str[start + len] == delimiter && quote == 0)
			break ;
		len++;
	}
	return (len);
}

static int	fill_line(char const *str, char **line_to_fill, int *last_index,
		char delimiter)
{
	int	start;
	int	len;

	start = *last_index;
	while (str[start] == delimiter)
		start++;
	len = calculate_word_len(str, start, delimiter);
	*line_to_fill = malloc(sizeof(char) * (len + 1));
	if (!*line_to_fill)
		return (0);
	ft_strlcpy(*line_to_fill, str + start, len + 1);
	*last_index = start + len + (str[start + len] != '\0');
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
			return (ft_bi_array_free(result), NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}
