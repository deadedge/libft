/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_advanced.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:45:29 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/04 15:24:53 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int		i;
	int		str_len;
	int		count;
	char	quote;

	i = 0;
	count = 0;
	str_len = ft_strlen(str);
	quote = 0;
	while (str[i] == c)
		i++;
	while (i < str_len)
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (quote == 0)
				quote = str[i];
			else if (quote == str[i])
				quote = 0;
		}
		if (str[i] == c && quote == 0 && i + 1 < str_len)
			count++;
		i++;
	}
	return (count + 1);
}

static int	fill_line(char const *str, char **line_to_fill, int *last_index,
		char delimiter)
{
	int		start;
	int		len;
	char	quote;

	start = *last_index;
	len = 0;
	quote = 0;
	while (str[start] == delimiter)
		start++;
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
	*line_to_fill = malloc(sizeof(char) * (len + 1));
	if (!*line_to_fill)
		return (0);
	ft_strlcpy(*line_to_fill, str + start, len + 1);
	return ((*last_index = start + len + 1), 1);
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
