/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:52:05 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/29 15:04:57 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || !s[i])
				count++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		tab_num;
	char	**lng_str;

	tab_num = count_words(s, c);
	lng_str = (char **)malloc(sizeof(char *) * (tab_num + 1));
	if (!lng_str)
		return (NULL);
}

int	main(void)
{
	char	*s = "AB CDEF GHI";
	char	c = ' ';

	printf("%s", ft_split(s, c));
	return (0);
}
