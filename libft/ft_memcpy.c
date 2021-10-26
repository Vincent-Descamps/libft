/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:02:41 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/26 12:16:59 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	char	*dest;

	dest = dst;
	if (!src && !dst)
		return (0);
	while (n > 0)
	{
		(*(unsigned char *)dst++) = (*(unsigned char *)src++);
		n--;
	}
	return (dest);
}
/*
int main()
{
    char dst[] = "flip";
    char src[] = "********";

    printf("avant ft_memcpy : %s\n", dst);

    ft_memcpy(dst, src, 4);

	printf("apres ft_memcpy : %s", dst);
    return 0;
}
*/
