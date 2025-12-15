/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:46:02 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/15 16:05:34 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_string_format.h"

static int	write_custom(char format, va_list *args, char **str_ptr)
{
	if (format == CHAR)
		return (format_char(va_arg(*args, int), str_ptr));
	else if (format == STRING)
		return (format_string(va_arg(*args, char *), str_ptr));
	else if (format == INTEGER || format == DECIMAL)
		return (format_number(va_arg(*args, int), str_ptr));
	else if (format == POINTER)
		return (format_hex(va_arg(*args, unsigned long long), str_ptr));
	else if (format == UNSDECIMAL)
		return (format_unsinged_int(va_arg(*args, unsigned int), str_ptr));
	else if (format == NUMBERHEXLOWER)
		return (format_number_to_hex(va_arg(*args, unsigned int), 0, str_ptr));
	else if (format == NUMBERHEXUPPER)
		return (format_number_to_hex(va_arg(*args, unsigned int), 1, str_ptr));
	else if (format == PERCENT)
		return (format_char('%', str_ptr));
	return (-1);
}

static int	process_format(const char *format, va_list *args, char **str_ptr)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
			len += write_custom(format[++i], args, str_ptr);
		else
			len += format_char(format[i], str_ptr);
		i++;
	}
	return (len);
}

char	*ft_str_format(const char *format, ...)
{
	va_list			args;
	unsigned int	len;
	char			*res;
	char			*ptr;

	va_start(args, format);
	len = process_format(format, &args, NULL);
	va_end(args);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ptr = res;
	va_start(args, format);
	process_format(format, &args, &ptr);
	va_end(args);
	*ptr = '\0';
	return (res);
}
