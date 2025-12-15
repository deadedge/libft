/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_format.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:55:20 by joao-cor          #+#    #+#             */
/*   Updated: 2025/12/15 16:08:25 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_FORMAT
# define FT_STR_FORMAT

// include external libs
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// lib functions
char	*ft_str_format(const char *format, ...);
int		format_char(char c, char **str_ptr);
int		format_string(char *str, char **str_ptr);
int		format_number(int nb, char **str_ptr);
int		format_hex(unsigned long long pointer, char **str_ptr);
int		format_unsinged_int(unsigned int number, char **str_ptr);
int		format_number_to_hex(unsigned int number, int isUpper, char **str_ptr);
char	*format_convert_to_hex(unsigned long long num);

// enums
typedef enum f_formats
{
	F_CHAR = 'c',
	F_STRING = 's',
	F_DECIMAL = 'd',
	F_INTEGER = 'i',
	F_POINTER = 'p',
	F_UNSDECIMAL = 'u',
	F_NUMBERHEXLOWER = 'x',
	F_NUMBERHEXUPPER = 'X',
	F_PERCENT = '%',
}		t_t_formats;

#endif