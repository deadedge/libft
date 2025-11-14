/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:24:19 by joao-cor          #+#    #+#             */
/*   Updated: 2025/11/14 14:34:06 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_array_dup(char **arr)
{
	int		i;
	char	**result;
	char	*line;
	int		len;

	i = 0;
	while (arr[i])
		i++;
	result = ft_calloc(i + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		line = malloc(sizeof(char) * len + 1);
		if (!line)
			return (ft_bi_array_free(result), NULL);
		ft_memmove(line, arr[i], len + 1);
		result[i] = line;
		i++;
	}
	return (result[i] = NULL, result);
}
