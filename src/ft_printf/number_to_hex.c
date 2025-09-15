/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:54:29 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include "libft.h"

int	write_number_to_hex(unsigned int number, int isUpper)
{
	char	*converted;
	int		len;

	len = 0;
	converted = convert_to_hex(number);
	if (isUpper)
		ft_strtoupper(converted);
	len += write_string(converted);
	free(converted);
	return (len);
}
