/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:59:14 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/26 23:51:42 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const set)
{
	int		i;
	int		j;
	char	*s1_cpy;

	i = 0;
	j = 0;
	s1_cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) - ???));
	while (s1[i] != '\0')
	{
		if (s1[i] == set)
			i++;
		while (s1[i] != set)
		{
			s1_cpy[j] = s1[i];
			j++;
		}
	}
	return (s1_cpy);
}

int	main(void)
{
	char s1[] = "	Jusqu'ici tout va bien.	";
	char set = '\t';

	printf("%s", ft_strtrim(s1, set));
}
