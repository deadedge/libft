/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:52:24 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			*ptr;
	unsigned int	i;
	void			*ptr_val;
	size_t			len;

	len = nmemb * size;
	if (size && (len / size) != nmemb)
		return (NULL);
	ptr = malloc(len);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	ptr_val = ptr;
	while (i < len)
	{
		*(unsigned char *)ptr_val = '\0';
		ptr_val++;
		i++;
	}
	return (ptr);
}
