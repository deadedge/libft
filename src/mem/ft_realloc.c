/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:30:16 by joao-cor          #+#    #+#             */
/*   Updated: 2025/10/17 14:48:48 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t ptr_size, size_t size)
{
	unsigned char	*realloced_ptr;
	unsigned char	*ptr_bytes;
	size_t			i;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	i = 0;
	realloced_ptr = malloc(size);
	if (!realloced_ptr)
		return (NULL);
	ptr_bytes = (unsigned char *)ptr;
	if (ptr)
	{
		while (i < size)
		{
			if (i < ptr_size)
				realloced_ptr[i] = ptr_bytes[i];
			i++;
		}
		free(ptr);
	}
	return (realloced_ptr);
}
