/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:38:38 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/22 16:48:15 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void    *ft_memmove(void *dest, const void *src, size_t len)
{
    unsigned char *d;
    unsigned char *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    if (dest == src)
        return (dest);
    if (s < d)
    {
        while(len--)
            d[len] = s[len];
        return (dest);
    }
    while (len--)
        *d++ = *s++;
    return (dest);
}
int	main(void)
{
	char	dst[] = "flip";
	char	src[] = "********";

	printf("avant ft_memmove : %s\n", dst);
	ft_memmove(dst, src, 4);
	printf("apres ft_memmove : %s", dst);
	return (0);
}
