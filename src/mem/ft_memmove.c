/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:08:49 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int numBytes)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned int		i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (d > s && d < s + numBytes)
	{
		while (numBytes--)
			d[numBytes] = s[numBytes];
	}
	else
	{
		while (i < numBytes)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

// int main(){

// 	char str[20] = "HELLOSIR";
// 	int test = -1;
// 	int teste2 = 0;
// 	ft_memmove(&teste2 ,&test, 3);
// 	printf("%d",teste2);

// 	return (0);
// }