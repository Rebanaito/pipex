/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 06:49:44 by revanite          #+#    #+#             */
/*   Updated: 2023/05/20 06:29:49 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	else if (n)
	{
		i = n - 1;
		while (i > 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
		*(char *)(dest + i) = *(char *)(src + i);
	}
	return (dest);
}
