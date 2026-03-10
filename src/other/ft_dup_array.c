/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:12:06 by jocas             #+#    #+#             */
/*   Updated: 2026/03/09 15:19:45 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_array(char **arr)
{
	int		i;
	char	**result;

	i = 0;
	result = malloc(sizeof(char *) * (ft_by_array_len(arr) + 1));
	if (!result)
		return (NULL);
	while (arr[i])
	{
		result[i] = ft_strdup(arr[i]);
		if (!result[i])
			return (ft_bi_array_free(result), NULL);
		i++;
	}
	result[i] = 0;
	return (result);
}
