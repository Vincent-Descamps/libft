/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:52:57 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/18 17:02:48 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int  ft_strlen(const char *s)
{
    int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	*s = "jbjkbk jbuibwe";

	printf("%d", ft_strlen(s));
}
*/