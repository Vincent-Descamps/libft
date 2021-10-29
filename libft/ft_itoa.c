/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:54:16 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/29 14:14:16 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digit(int n)
{
	int			count;
	long int	i;

	i = n;
	count = 1;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 9)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			str_len;
	long int	nbr;

	nbr = n;
	str_len = count_digit(n);
	str = malloc(sizeof(char) * (str_len + 1));
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	i = str_len - 1;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 10)
		str[0] = nbr + '0';
	while (i >= 0 && nbr != 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	str[str_len] = '\0';
	return (str);
}
/*
int	main(void)
{
	int	n;

	n = -123;
	ft_itoa(n);
	return (0);
}
*/
