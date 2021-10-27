/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:17:45 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/27 17:18:08 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
char	check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s1_cpy;

	start = 0;
	while (s1[start] && check(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && check(s1[end - 1], set))
		end--;
	s1_cpy = (char *)malloc((sizeof(char)) * (end - start + 1));
	if (!s1_cpy)
		return (0);
	i = 0;
	s1_cpy[i++] = s1[start++];
	s1_cpy[i] = '\0';
	return (s1_cpy);
}
*/
