/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_format.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:55:20 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/15 15:55:00 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// include external libs
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// lib functions
char	*ft_str_format(const char *format, ...);
int		write_char(char c, char **str_ptr);
int		write_string(char *str, char **str_ptr);
int		write_number(int nb, char **str_ptr);
int		write_hex(unsigned long long pointer, char **str_ptr);
int		write_unsinged_int(unsigned int number, char **str_ptr);
int		write_number_to_hex(unsigned int number, int isUpper, char **str_ptr);
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