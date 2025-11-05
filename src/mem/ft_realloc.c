/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:30:16 by joao-cor          #+#    #+#             */
/*   Updated: 2025/11/05 12:18:45 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	unsigned char	*new_ptr;
	unsigned char	*old_bytes;
	size_t			i;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	i = 0;
	old_bytes = (unsigned char *)ptr;
	while (i < new_size)
	{
		new_ptr[i] = '\0';
		if (ptr && i < old_size)
			new_ptr[i] = old_bytes[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}
