/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:57:19 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char			*last_occurrence;

	last_occurrence = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			last_occurrence = (char *)&str[i];
		i++;
	}
	if (str[i] == (unsigned char)c)
		last_occurrence = (char *)&str[i];
	if (last_occurrence != NULL)
		return (last_occurrence);
	return (NULL);
}
