/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_callback_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:44:47 by joao-cor          #+#    #+#             */
/*   Updated: 2026/03/09 11:23:44 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_array_callback_i(char **arr, void (*f)(int, char *))
{
	unsigned int	i;

	if (!arr || !*arr || !f)
		return ;
	i = 0;
	while (arr[i])
	{
		(*f)(i, arr[i]);
		i++;
	}
	return ;
}
