/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:47:38 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/15 15:55:00 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./ft_string_format.h"
#include "libft.h"

int	write_number(int nb, char **str_ptr)
{
	char	*value;
	int		len;

	value = ft_itoa(nb);
	len = write_string(value, str_ptr);
	free(value);
	return (len);
}
