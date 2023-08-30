/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:45:57 by revanite          #+#    #+#             */
/*   Updated: 2023/05/18 23:57:23 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(sizeof(char) * len);
	if (p == NULL)
		return (NULL);
	ft_strcpy(p, (char *)s1);
	ft_strcat(p, (char *)s2);
	return (p);
}
