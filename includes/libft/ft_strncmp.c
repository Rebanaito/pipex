/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 07:34:07 by revanite          #+#    #+#             */
/*   Updated: 2023/05/18 12:14:16 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	if (!n)
		return (0);
	while (n)
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (!c1 || c1 != c2)
			break ;
		n--;
	}
	return (c1 - c2);
}
