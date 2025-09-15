/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:58:53 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	ssize_t	i;
	size_t	j;
	char	*join_str;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	join_str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!join_str)
		return (NULL);
	while (s1 && s1[i])
	{
		join_str[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2 && s2[i])
		join_str[j++] = s2[i++];
	join_str[j] = '\0';
	return (join_str);
}

// int main(void){
// 	printf("%s",ft_strjoin("jocas","docas"));
// 	return (0);
// }