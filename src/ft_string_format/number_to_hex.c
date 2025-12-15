/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:54:29 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/15 15:55:00 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./ft_string_format.h"
#include "libft.h"

int	write_number_to_hex(unsigned int number, int isUpper, char **str_ptr)
{
	char	*converted;
	int		len;

	len = 0;
	converted = convert_to_hex(number);
	if (isUpper)
		ft_strtoupper(converted);
	len += write_string(converted, str_ptr);
	free(converted);
	return (len);
}
