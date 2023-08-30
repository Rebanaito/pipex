/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:05:03 by ekolosov          #+#    #+#             */
/*   Updated: 2023/07/15 07:59:37 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	split_strings(char *s, char c, char **split);
static int	alloc_and_write(char **split, char *s, int count, int len);

char	**ft_split_quotes(char const *s, char c)
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

static void	quotes(char **tmp, char c, char *quote)
{
	if ((**tmp == '\'' && c != '\'') || (**tmp == '"' && c != '"'))
	{
		if (!*quote)
			*quote = **tmp;
		else
			*quote = 0;
	}
	(*tmp)++;
}

static void	normin_time(char c, char **tmp, char **s, int *count)
{
	if (c)
		while (**tmp == c)
			(*tmp)++;
	*s = *tmp;
	(*count)++;
}

static int	split_strings(char *s, char c, char **split)
{
	int		count;
	char	quote;
	char	*tmp;

	count = 0;
	quote = 0;
	while (*s == c && *s)
		s++;
	tmp = s;
	while (*s || *tmp)
	{
		if ((*tmp != c || quote) && *s && *tmp)
			quotes(&tmp, c, &quote);
		else
		{
			if (split != NULL)
				if (alloc_and_write(split, s, count, tmp - s))
					return (-1);
			normin_time(c, &tmp, &s, &count);
		}
	}
	return (count);
}

static int	alloc_and_write(char **split, char *s, int count, int len)
{
	if (((*s == '\'' && *(s + len - 1) == '\'')
			|| (*s == '"' && *(s + len - 1) == '"')) && len > 1)
	{
		s++;
		len -= 2;
	}
	split[count] = (char *)malloc(sizeof(char) * (len + 1));
	if (split[count] == NULL)
		return (1);
	ft_strncpy(split[count], s, len);
	return (0);
}
