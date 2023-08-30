/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revanite <revanite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:17:16 by revanite          #+#    #+#             */
/*   Updated: 2023/05/20 06:57:00 by revanite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	split_strings(char *s, char c, char **split);
static int	alloc_and_write(char **split, char *s, int count, int len);

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;
	int		i;

	count = split_strings((char *)s, c, NULL);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i <= count)
		split[i++] = NULL;
	i = 0;
	if (split_strings((char *)s, c, split) == -1)
	{
		while (i < count && split[i] != NULL)
			free(split[i++]);
		free(split);
		return (NULL);
	}
	return (split);
}

static int	split_strings(char *s, char c, char **split)
{
	int		count;
	char	*tmp;

	count = 0;
	while (*s == c && *s)
		s++;
	tmp = s;
	while (*s || *tmp)
	{
		if (*tmp != c && *s && *tmp)
			tmp++;
		else
		{
			if (split != NULL)
				if (alloc_and_write(split, s, count, tmp - s))
					return (-1);
			if (c)
				while (*tmp == c)
					tmp++;
			s = tmp;
			count++;
		}
	}
	return (count);
}

static int	alloc_and_write(char **split, char *s, int count, int len)
{
	split[count] = (char *)malloc(sizeof(char) * (len + 1));
	if (split[count] == NULL)
		return (1);
	ft_strncpy(split[count], s, len);
	return (0);
}
