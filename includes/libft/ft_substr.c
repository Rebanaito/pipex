/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:39:06 by revanite          #+#    #+#             */
/*   Updated: 2023/05/24 11:24:39 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		if (len < ft_strlen(s) - start)
			p = (char *)malloc(len + 1);
		else
			p = (char *)malloc(ft_strlen(s) - start + 1);
		if (p == NULL)
			return (NULL);
		while (i < len && s[start])
			p[i++] = s[start++];
	}
	else
	{
		p = (char *)malloc(1);
		if (p == NULL)
			return (NULL);
	}
	p[i] = 0;
	return (p);
}
