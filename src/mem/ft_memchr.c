/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:38:32 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str_value;

	str_value = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (str_value[i] == (unsigned char)c)
			return (&str_value[i]);
		i++;
	}
	return (NULL);
}
