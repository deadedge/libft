/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:46:02 by joao-cor          #+#    #+#             */
/*   Updated: 2025/06/12 14:45:24 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	write_custom(char format, va_list *args)
{
	if (format == CHAR)
		return (write_char(va_arg(*args, int)));
	else if (format == STRING)
		return (write_string(va_arg(*args, char *)));
	else if (format == INTEGER || format == DECIMAL)
		return (write_number(va_arg(*args, int)));
	else if (format == POINTER)
		return (write_hex(va_arg(*args, unsigned long long)));
	else if (format == UNSDECIMAL)
		return (write_unsinged_int(va_arg(*args, unsigned int)));
	else if (format == NUMBERHEXLOWER)
		return (write_number_to_hex(va_arg(*args, unsigned int), 0));
	else if (format == NUMBERHEXUPPER)
		return (write_number_to_hex(va_arg(*args, unsigned int), 1));
	else if (format == PERCENT)
		return (write_char('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	lenght_print;

	i = 0;
	lenght_print = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			lenght_print += write_custom(format[++i], &args);
		else
			lenght_print += write_char(format[i]);
		i++;
	}
	va_end(args);
	return (lenght_print);
}
