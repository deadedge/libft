/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:54:29 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/28 23:50:16 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_string_format.h"
#include "libft.h"

int	format_number_to_hex(unsigned int number, int isUpper, char **str_ptr)
{
	char	*converted;
	int		len;

	len = 0;
	converted = format_convert_to_hex(number);
	if (isUpper)
		ft_strtoupper(converted);
	len += format_string(converted, str_ptr);
	free(converted);
	return (len);
}
