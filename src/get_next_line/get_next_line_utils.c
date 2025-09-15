/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:03:33 by joao-cor          #+#    #+#             */
/*   Updated: 2025/07/14 13:49:12 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen_custom(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	if (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin_custom(char *s1, char *s2, ssize_t stop_index)
{
	ssize_t	i;
	size_t	j;
	char	*join_str;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	join_str = malloc(sizeof(char) * ((ft_strlen_custom(s1) + stop_index) + 1));
	if (!join_str)
		return (NULL);
	while (s1 && s1[i])
	{
		join_str[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2 && s2[i] && i < stop_index)
		join_str[j++] = s2[i++];
	join_str[j] = '\0';
	return (join_str);
}

t_strchr_return	*ft_strchr_custom(const char *str, int search_str)
{
	ssize_t	i;

	t_strchr_return(*result);
	result = malloc(sizeof(t_strchr_return));
	if (!result)
		return (NULL);
	result->finded_pos = -1;
	result->finded_str = "";
	result->string_finalized = 0;
	i = 0;
	while (str[i] && str[i] != (char)search_str)
	{
		i++;
	}
	if (str[i] == (char)search_str)
	{
		result->finded_pos = i;
		result->finded_str = &str[i];
	}
	if (!str[i])
		result->string_finalized = 1;
	return (result);
}

void	*ft_memmove_and_clear(void *dest, const void *src, ssize_t numBytes,
		ssize_t max_lenght)
{
	unsigned char		*d;
	const unsigned char	*s;
	ssize_t				saved_bytes_len;
	ssize_t				i;

	if (!dest && !src)
		return (NULL);
	saved_bytes_len = numBytes;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s && d < s + numBytes)
	{
		while (numBytes--)
			d[numBytes] = s[numBytes];
	}
	else
	{
		i = -1;
		while (++i < numBytes)
			d[i] = s[i];
	}
	while (saved_bytes_len < max_lenght)
		d[++saved_bytes_len] = '\0';
	return (d[saved_bytes_len] = '\0', dest);
}

void	clear_str(char *str)
{
	ssize_t	i;

	i = 0;
	while (str && str[i])
		str[i++] = '\0';
	str[i] = '\0';
}
