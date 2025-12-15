/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:45:37 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/15 15:55:00 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./ft_string_format.h"
#include "libft.h"

int	write_hex(unsigned long long num, char **str_ptr)
{
	char	*converted;
	int		len;

	len = 0;
	if (num == 0)
		return ((len += write_string("(nil)", str_ptr)), len);
	converted = convert_to_hex(num);
	len += write_string("0x", str_ptr);
	len += write_string(converted, str_ptr);
	free(converted);
	return (len);
}
