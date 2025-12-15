/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:46:35 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/15 16:05:03 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./ft_string_format.h"

int	format_string(char *str, char **str_ptr)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
		return (format_string("(null)", str_ptr));
	while (str[i])
		format_char(str[i++], str_ptr);
	return (i);
}
