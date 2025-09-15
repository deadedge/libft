/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deadedge <deadedge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:02:57 by joao-cor          #+#    #+#             */
/*   Updated: 2025/07/23 15:29:48 by deadedge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int	processing_information(char **result, char *buffer)
{
	ssize_t	i;
	ssize_t	buffer_len;
	char	*temp;

	t_strchr_return(*finded_result);
	finded_result = ft_strchr_custom(buffer, '\n');
	i = finded_result->finded_pos;
	if (!finded_result)
		return (0);
	if (i == -1)
		i = ft_strlen_custom(buffer);
	temp = ft_strjoin_custom(*result, buffer, (i + 1));
	i = 0;
	if (*result)
		free(*result);
	*result = temp;
	buffer_len = ft_strlen_custom(buffer);
	if (finded_result->string_finalized)
		clear_str(buffer);
	else
		ft_memmove_and_clear(buffer, finded_result->finded_str + 1, (buffer_len
				- (finded_result->finded_pos)) + 1, buffer_len);
	if (finded_result->finded_pos != -1)
		return (free(finded_result), 2);
	return (free(finded_result), 1);
}

static void	read_next(int fd, char **result, char *buffer)
{
	ssize_t	readed_bytes;

	while (1)
	{
		if (buffer[0])
		{
			if (processing_information(result, buffer) == 2)
				break ;
		}
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes <= 0)
		{
			if (((*result) && (*result)[0]) || !buffer[0])
				break ;
			processing_information(result, buffer);
			continue ;
		}
		if (processing_information(result, buffer) == 2)
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	result = NULL;
	read_next(fd, &result, buffer);
	return (result);
}
