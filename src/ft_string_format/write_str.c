/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:46:35 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/15 15:55:00 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./ft_string_format.h"

int	write_string(char *str, char **str_ptr)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
		return (write_string("(null)", str_ptr));
	while (str[i])
		write_char(str[i++], str_ptr);
	return (i);
}
