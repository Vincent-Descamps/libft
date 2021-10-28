/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:54:16 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/28 13:34:18 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    count_digit(int n)
{
	int    count;

	count = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		str_len;

	str_len = count_digit(n);
	str = malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	i = str_len - 1;
	if (n < 0)
	{
		n *= -1;
		str = malloc(sizeof(char) * (str_len + 2));
		str[0] = '-';
		i = str_len;
	}
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[str_len] = '\0';
}

int	main(void)
{
	int	n;

	n = -123;
	ft_itoa(n);
	return (0);
}
