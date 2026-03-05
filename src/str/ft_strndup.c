/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:00:48 by joao-cor          #+#    #+#             */
/*   Updated: 2026/03/05 14:58:00 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, int len, char insert_char)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	while (i < len)
	{
		new_str[i] = insert_char;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
