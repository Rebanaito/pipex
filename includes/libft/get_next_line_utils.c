/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 05:12:58 by revanite          #+#    #+#             */
/*   Updated: 2023/06/19 09:29:29 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_recalloc(char **line, size_t size)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(size);
	if (new == NULL)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	i = 0;
	while (i < size)
		new[i++] = 0;
	i = 0;
	if (*line)
	{
		while ((*line)[i])
		{
			new[i] = (*line)[i];
			i++;
		}
		free(*line);
	}
	return (new);
}

char	*ft_strncat(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

long	find_nl(const char *buffer, int opt)
{
	long	len;

	len = -1;
	if (!opt)
	{
		if (buffer == NULL)
			return (0);
		while (buffer[++len])
		{
			if (buffer[len] == '\n')
			{
				len++;
				return (len);
			}
		}
		return (-1);
	}
	else
	{
		if (!buffer)
			return (0);
		while (buffer[++len])
			(void)len;
		return (len);
	}
}

int	ft_mem(char **s, int c, size_t n, int opt)
{
	size_t	i;

	if (!opt)
	{
		i = -1;
		while (++i < n)
			*((*s) + i) = (char)c;
		return (1);
	}
	else
	{
		free(*s);
		*s = NULL;
		return (0);
	}
}

void	leftovers(char **buffer, char **line, int opt, size_t len)
{
	if (!opt)
	{
		ft_strncat(*buffer, (*line + find_nl(*line, 0)),
			find_nl(*line, 1) - find_nl(*line, 0));
		*line = ft_recalloc(line, (size_t)find_nl(*line, 0) + 1);
		if (*line == NULL)
			ft_mem(buffer, 0, 0, 1);
	}
	else
	{
		ft_strncat(*line, *buffer, len);
		shift_buffer(buffer);
	}
}
