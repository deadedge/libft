/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:54:52 by joao-cor          #+#    #+#             */
/*   Updated: 2025/05/26 11:08:17 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	unsigned char	*point;

	i = 0;
	point = (unsigned char *)s;
	while (i < n)
	{
		point[i] = '\0';
		i++;
	}
}
