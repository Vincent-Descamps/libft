/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:00:28 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/20 17:25:29 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0')
		{
			if (needle[j + 1] == '\0')
				return (needle[j]);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	haystack[] = "ou est l'aiguille dans la botte de foin?";
	char	needle[] = "dans";
	char	*ptr;

	ptr = ft_strnstr(haystack, needle, 4);
	printf("%s", ptr);
}
