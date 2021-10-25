/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:45:29 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/25 18:34:09 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(len + 1);
	if (!str)
		return (0);
	if (start >= ft_strlen(s))
		return ("");
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	str[] = "Salut les potos";
	unsigned	int start = 1;
	size_t	len = 3;

	//printf("%s\n", str);
	printf("%s", ft_substr(str, start, len));
}
*/
