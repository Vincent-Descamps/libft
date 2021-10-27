/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescamp <vdescamp@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:52:05 by vdescamp          #+#    #+#             */
/*   Updated: 2021/10/27 18:17:07 by vdescamp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_split(char const *s, char c)
{

}

int	main(void)
{
	char	*s;
	char	c;

	s = "C'est parti pour le split";
	c = " ";
	printf("%s", ft_split(s, c));
}
