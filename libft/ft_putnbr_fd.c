/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:30:09 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/30 14:32:54 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		str;
	long int	nb;

	nb = n;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 12);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		str = nb % 10 + '0';
	}
	else
		str = nb + '0';
	write(fd, &str, 1);
}
