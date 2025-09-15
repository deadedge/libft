/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:05:57 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	little_len;
	unsigned int	j;

	if (!*little || (!big && !len))
		return ((char *)big);
	i = 0;
	j = 0;
	little_len = ft_strlen(little);
	while ((big[i] && i < len))
	{
		if (j == little_len)
			return ((char *)&big[i]);
		if (big[i + j] == little[j] && i + j < len)
		{
			j++;
			continue ;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
