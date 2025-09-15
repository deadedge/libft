/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:46:35 by joao-cor          #+#    #+#             */
/*   Updated: 2025/06/12 14:32:55 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	write_string(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
		return (write_string("(null)"));
	while (str[i])
		write_char(str[i++]);
	return (i);
}
