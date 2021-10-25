/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:17:39 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/25 16:14:03 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[j] != '\0' && i < dstsize - 1)
		dst[i++] = src[j++];
	if (dstsize != 0 && dstsize >= ft_strlen(dst))
		dst[i] = '\0';
	if (dstsize > ft_strlen(dst))
		return (ft_strlen(dst) + ft_strlen(src));
	return (dstsize + ft_strlen(src));
}

int	main(void)
{
	char	str1[] = "123456";
	char	str2[] = "789";

	printf("%zu", ft_strlcat(str1, str2, 3));
}

