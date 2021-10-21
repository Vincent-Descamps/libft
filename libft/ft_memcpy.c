/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:02:41 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/21 20:35:18 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	if (src == NULL && dst == NULL)
		return (0);
	while (n > 0)
	{
		(*(unsigned char *)dst++) = (*(unsigned char *)src++);
		n--;
	}
	return (dst);
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
