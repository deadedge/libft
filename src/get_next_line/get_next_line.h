/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:00:18 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// define buffer size if not sended
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// include external libs
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_strchr_return
{
	const char	*finded_str;
	ssize_t		finded_pos;
	int			string_finalized;
}			t_strchr_return;

// functions
char			*get_next_line(int fd);
char			*ft_strjoin_custom(char *s1, char *s2, ssize_t stop_index);
t_strchr_return(*ft_strchr_custom(const char *str, int search_str));

ssize_t			ft_strlen_custom(const char *str);
void			*ft_memmove_and_clear(void *dest, const void *src,
					ssize_t numBytes, ssize_t max_lenght);
void			clear_str(char *str);

#endif