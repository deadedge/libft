/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:45:37 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/28 23:51:18 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_string_format.h"
#include "libft.h"

int	format_hex(unsigned long long num, char **str_ptr)
{
	char	*converted;
	int		len;

	len = 0;
	if (num == 0)
		return ((len += format_string("(nil)", str_ptr)), len);
	converted = format_convert_to_hex(num);
	len += format_string("0x", str_ptr);
	len += format_string(converted, str_ptr);
	free(converted);
	return (len);
}
