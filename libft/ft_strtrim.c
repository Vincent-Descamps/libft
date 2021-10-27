/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:59:14 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/27 17:50:18 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*s1_cpy;

	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
		start++;
	if (!(start))
		return (ft_strdup(""));
	end = (char *)s1;
	while (*end)
		end++;
	while (ft_strchr(set, *end))
		end--;
	while (start >= end)
		return (ft_strdup(""));
	s1_cpy = (char *)malloc((end - start + 1) + 1);
	if (!s1_cpy)
		return (0);
	ft_strlcpy(s1_cpy, start, ((end - start) + 1) + 1);
	return (s1_cpy);
}
/*
int	main(void)
{
	char	s1[] = "	Jusqu'ici tout va bien.		";
	char	*set;
	set = "	";

	printf("%s", ft_strtrim(s1, set));
}
*/
