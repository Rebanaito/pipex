/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:10:09 by revanite          #+#    #+#             */
/*   Updated: 2023/05/15 13:47:55 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *src)
{
	int		size;
	char	*res;

	size = ft_strlen(src) + 1;
	res = (char *)malloc(size * sizeof(char));
	if (res == NULL)
		return (NULL);
	res = ft_strcpy(res, (char *)src);
	return (res);
}
