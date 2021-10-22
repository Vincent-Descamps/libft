/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:04:00 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/22 17:47:02 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src == NULL && dst == NULL)
		return (0);
	if ((unsigned char *)dst < (unsigned char *)src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char	dst[] = "flip";
	char	src[] = "********";

	printf("avant ft_memmove : %s\n", dst);
	ft_memmove(dst, src, 4);
	printf("apres ft_memmove : %s", dst);
	return (0);
}
*/
