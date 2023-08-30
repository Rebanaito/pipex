/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 07:20:30 by revanite          #+#    #+#             */
/*   Updated: 2023/05/20 02:27:42 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*src_copy;
	char	*dest_copy;
	size_t	size_copy;
	size_t	dest_length;

	dest_copy = dest;
	src_copy = (char *)src;
	size_copy = size;
	while (size_copy-- && *dest_copy)
		dest_copy++;
	dest_length = dest_copy - dest;
	size_copy = size - dest_length;
	if (!size_copy)
		return (dest_length + ft_strlen(src));
	while (*src_copy)
	{
		if (size_copy > 1)
		{
			*dest_copy++ = *src_copy;
			size_copy--;
		}
		src_copy++;
	}
	*dest_copy = 0;
	return (dest_length + (src_copy - src));
}
