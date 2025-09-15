/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocas <jocas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:32:31 by joao-cor          #+#    #+#             */
/*   Updated: 2025/09/15 15:01:27 by jocas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (!n || !fd)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		n = (n % 10);
	}
	if (n < 10)
		n = n + 48;
	write(fd, &n, 1);
}

/* int	main(void)
{
	char *fileName = "sample.txt";

	int fd = open(fileName, O_RDWR);

	if (fd == -1)
	{
		printf("\nError Opening File!!\n");
		exit(1);
	}
	else
	{
		printf("\nFile %s opened successfully!\n", fileName);
	}
	ft_putnbr_fd(-123213, fd);
	return (0);
} */