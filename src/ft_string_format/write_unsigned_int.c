/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:50:15 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/15 15:55:00 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./ft_string_format.h"
#include "libft.h"

int	write_unsinged_int(unsigned int number, char **str_ptr)
{
	char	*value;
	int		len;

	if (number == 0)
		return (write_char('0', str_ptr));
	value = ft_unsigned_itoa(number);
	len = write_string(value, str_ptr);
	free(value);
	return (len);
}
