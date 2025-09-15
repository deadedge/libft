/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:45:37 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include "libft.h"

int	write_hex(unsigned long long num)
{
	char	*converted;
	int		len;

	len = 0;
	if (num == 0)
		return ((len += write_string("(nil)")), len);
	converted = convert_to_hex(num);
	len += write_string("0x");
	len += write_string(converted);
	free(converted);
	return (len);
}
