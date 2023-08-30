/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 07:56:52 by revanite          #+#    #+#             */
/*   Updated: 2023/05/20 03:28:09 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		len_sub;
	char		*p;

	i = 0;
	len_sub = ft_strlen(little);
	if (!len && !len_sub)
		return ((char *)big);
	p = (char *)big;
	while (p[i] && i < len && len_sub <= len - i)
	{
		if (!ft_strncmp(p + i, little, len_sub))
			return (p + i);
		i++;
	}
	if (!ft_strncmp(p + i, little, len_sub) && len_sub <= len - i)
		return (p + i);
	return (NULL);
}
