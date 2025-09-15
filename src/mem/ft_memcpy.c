/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:25:36 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, unsigned int n)
{
	unsigned int	i;
	unsigned char	*src_value;
	unsigned char	*dest_value;

	if (!dest_str && !src_str)
		return (NULL);
	i = 0;
	src_value = (unsigned char *)src_str;
	dest_value = (unsigned char *)dest_str;
	while (i < n)
	{
		dest_value[i] = src_value[i];
		i++;
	}
	return (dest_str);
}
