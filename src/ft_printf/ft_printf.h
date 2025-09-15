/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:55:20 by joao-cor          #+#    #+#             */
/*   Updated: 2025/05/26 11:19:27 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// include external libs
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

// lib functions
int		ft_printf(const char *format, ...);
int		write_char(char c);
int		write_string(char *str);
int		write_number(int nb);
int		write_number(int nb);
int		write_hex(unsigned long long pointer);
int		write_unsinged_int(unsigned int number);
int		write_number_to_hex(unsigned int number, int isUpper);
char	*convert_to_hex(unsigned long long num);

// enums
typedef enum formats
{
	CHAR = 'c',
	STRING = 's',
	DECIMAL = 'd',
	INTEGER = 'i',
	POINTER = 'p',
	UNSDECIMAL = 'u',
	NUMBERHEXLOWER = 'x',
	NUMBERHEXUPPER = 'X',
	PERCENT = '%',
}		t_formats;

#endif