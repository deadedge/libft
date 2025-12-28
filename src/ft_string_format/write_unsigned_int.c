/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:50:15 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/28 23:50:41 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_string_format.h"
#include "libft.h"

int	format_unsinged_int(unsigned int number, char **str_ptr)
{
	char	*value;
	int		len;

	if (number == 0)
		return (format_char('0', str_ptr));
	value = ft_unsigned_itoa(number);
	len = format_string(value, str_ptr);
	free(value);
	return (len);
}
