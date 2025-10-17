/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:32:08 by joao-cor          #+#    #+#             */
/*   Updated: 2025/10/17 14:48:59 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../libft/src/ft_printf/ft_printf.h"
# include "../libft/src/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Functions
char				*ft_unsigned_itoa(unsigned int n);
void				ft_strtoupper(char *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				**ft_split_advanced(char const *s, char c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strjoin(char *s1, char *s2);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
int					ft_strfindfirst(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_strncmp(const char *str1, const char *str2,
						unsigned int n);
ssize_t				ft_strlen(const char *str);
unsigned int		ft_strlcpy(char *dest, const char *src, unsigned int size);
unsigned int		ft_strlcat(char *dest, const char *src, unsigned int size);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *str, int search_str);
void				*ft_memset(void *adress, int c, unsigned int n);
void				*ft_memmove(void *dest_str, const void *src_str,
						unsigned int numBytes);
void				*ft_memcpy(void *dest_str, const void *src_str,
						unsigned int n);
int					ft_memcmp(const void *str1, const void *str2,
						unsigned int n);
void				*ft_memchr(const void *str, int c, unsigned int n);
int					ft_isprint(int arg);
int					ft_isdigit(char n);
int					ft_isascii(int code);
int					ft_isalpha(char c);
int					ft_isalnum(char c);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, unsigned int n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_isdigit_complex(char *str);
void				ft_bi_array_free(char **arr);
void				ft_by_array_print(char **arr);
int					ft_by_array_len(char **arr);
long				ft_atol(const char *nptr);
int					ft_is_space(const char s);
void				*ft_realloc(void *ptr, size_t ptr_size, size_t size);

// STRUCTS

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_front(t_list **lst, t_list *newa);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);

#endif