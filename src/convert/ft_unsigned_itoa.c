/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:11:54 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_digits(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	unsigned int	digits;
	char			*result;

	digits = count_digits(n);
	result = malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	result[digits] = '\0';
	while (digits-- > 0)
	{
		result[digits] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
