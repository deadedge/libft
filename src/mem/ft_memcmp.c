/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:06:21 by joao-cor          #+#    #+#             */
/*   Updated: 2025/05/26 11:07:43 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *str1, const void *str2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str1_value;
	unsigned char	*str2_value;

	i = 0;
	str1_value = (unsigned char *)str1;
	str2_value = (unsigned char *)str2;
	while (i < n)
	{
		if (str1_value[i] != str2_value[i])
			return (str1_value[i] - str2_value[i]);
		i++;
	}
	return (0);
}
