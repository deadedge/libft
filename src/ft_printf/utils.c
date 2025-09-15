/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:53:22 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include "libft.h"

int	write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

void	inverte_string(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			temp;

	i = 0;
	j = ft_strlen(str) - 1;
	if (j == 0)
		return ;
	while (i < j)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i++;
		j--;
	}
}

char	*convert_to_hex(unsigned long long num)
{
	unsigned int	i;
	char			*result;
	char			*hex_digits;

	i = 0;
	if (num == 0)
		return (ft_strdup("0"));
	result = ft_calloc(17, sizeof(char));
	if (!result)
		return (NULL);
	hex_digits = "0123456789abcdef";
	result[0] = (num + '0');
	if (num >= 16)
	{
		while (num > 0)
		{
			result[i++] = hex_digits[num % 16];
			num /= 16;
		}
	}
	else if (num > 9)
		result[0] = (num - 10 + 'a');
	return (inverte_string(result), result);
}
