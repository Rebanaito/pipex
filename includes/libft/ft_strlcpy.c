/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 07:15:53 by revanite          #+#    #+#             */
/*   Updated: 2023/05/18 11:09:37 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	length;
	size_t	return_value;

	return_value = ft_strlen(src);
	if (size)
	{
		length = 0;
		while (src[length] && length < size - 1)
		{
			dest[length] = src[length];
			length++;
		}
		dest[length] = 0;
	}
	return (return_value);
}
