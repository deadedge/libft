/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_callback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:44:47 by joao-cor          #+#    #+#             */
/*   Updated: 2026/03/03 15:44:51 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_array_callback(char **arr, void (*f)(char *))
{
	unsigned int	i;

	if (!arr || !*arr || !f)
		return ;
	i = 0;
	while (arr[i])
	{
		(*f)(arr[i]);
		i++;
	}
	return ;
}
