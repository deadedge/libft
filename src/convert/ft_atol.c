/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:14:57 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/29 12:29:49 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(const char s)
{
	if ((s >= 9 && s <= 13) || s == 32)
	{
		return (1);
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	int signal;
	long value;

	signal = 1;
	value = 0;
	while (is_space(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		signal = -1;
		nptr++;
	}
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
	{
		value *= 10;
		value += (long)(*nptr++ - '0');
	}
	return (value * signal);
}