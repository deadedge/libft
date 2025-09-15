/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-cor <joao-cor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:17:21 by joao-cor          #+#    #+#             */
/*   Updated: 2025/05/26 11:04:13 by joao-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *adress, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)adress;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (adress);
}
