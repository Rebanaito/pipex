/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:56:25 by revanite          #+#    #+#             */
/*   Updated: 2023/05/20 06:53:09 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	set_match(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*p1;
	char const	*p2;
	char		*p;
	size_t		len;

	p1 = s1;
	p2 = p1;
	while (*p2)
		p2++;
	p2--;
	while (set_match(*p1, set))
		p1++;
	while (set_match(*p2, set) && p2 >= p1)
		p2--;
	len = p2 - p1 + 2;
	p = (char *)malloc(sizeof(char) * len);
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, p1, len);
	return (p);
}

static int	set_match(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}
