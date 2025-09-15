/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:01:15 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result_s;

	if (!s || !f)
		return (NULL);
	result_s = malloc(sizeof * s * (ft_strlen(s) + 1));
	if (result_s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result_s[i] = (*f)(i, s[i]);
		i++;
	}
	result_s[i] = '\0';
	return (result_s);
}

/*
 char my_func(unsigned int i, char str)
 {
	printf("My inner function: index = %d and %c\n", i, str);
	return (str - 32);
 }

 int main()
 {
	char str[10] = "hello.";
	printf("The result is %s\n", str);
	char *result = ft_strmapi(str, my_func);
	printf("The result is %s\n", result);
	free(result);
	return (0);
 }
 */