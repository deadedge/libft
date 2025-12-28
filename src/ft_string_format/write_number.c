/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:47:38 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/28 23:51:06 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_string_format.h"
#include "libft.h"

int	format_number(int nb, char **str_ptr)
{
	char	*value;
	int		len;

	value = ft_itoa(nb);
	len = format_string(value, str_ptr);
	free(value);
	return (len);
}
