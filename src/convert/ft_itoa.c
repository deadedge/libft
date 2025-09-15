/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:14:17 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	count_integer(int i)
{
	unsigned int	result;

	result = 0;
	if (i < 0)
		result++;
	while (i != 0)
	{
		i = i / 10;
		result++;
	}
	return (result);
}

char	*invert_string(char *s, int signal)
{
	unsigned int	i;
	unsigned int	j;
	char			temp;
	int				str_len;

	str_len = ft_strlen(s) - 1;
	if (signal == -1)
	{
		s[(str_len + 1)] = '-';
		str_len++;
	}
	i = 0;
	j = str_len;
	while (i < j)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		i++;
		j--;
	}
	s[str_len + 1] = '\0';
	return (s);
}

void	transform_integuer(int n, char *result_s, unsigned int *i)
{
	while (n != 0)
	{
		result_s[*i] = (char)((n % 10) + '0');
		(*i)++;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char			*result_s;
	int				signal;
	unsigned int	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	if (!n)
		return (NULL);
	i = 0;
	signal = 1;
	result_s = malloc(sizeof * result_s * (count_integer(n) + 1));
	if (result_s == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		signal = -1;
	}
	transform_integuer(n, result_s, &i);
	result_s[i] = 0;
	return (invert_string(result_s, signal));
}
