/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:42:56 by revanite          #+#    #+#             */
/*   Updated: 2023/06/19 09:29:39 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*end_of_line(char **line, char **buffer);
int		buffer_reset(char **line, char **buffer);
int		reading(char **line, char **buffer, int fd, ssize_t *bytes_read);
void	shift_buffer(char **buffer);

char	*get_next_line(int fd)
{
	static char			*buffer[1024];
	char				*line;
	ssize_t				bytes_read;

	line = NULL;
	bytes_read = 0;
	if (fd < 0 || fd > 1023)
		return (NULL);
	if (buffer[fd])
		if (end_of_line(&line, &buffer[fd]) == NULL)
			return (NULL);
	if (find_nl(line, 0) <= 0)
		if (!reading(&line, &buffer[fd], fd, &bytes_read))
			return (NULL);
	if (bytes_read == -1)
	{
		if (line)
			ft_mem(&line, 0, 0, 1);
		if (buffer[fd])
			ft_mem(&buffer[fd], 0, 0, 1);
	}
	return (end_of_line(&line, &buffer[fd]));
}

int	reading(char **line, char **buffer, int fd, ssize_t *bytes_read)
{
	if (*buffer == NULL)
	{
		*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (*buffer == NULL)
		{
			if (*line)
				ft_mem(line, 0, 0, 1);
			return (0);
		}
		ft_mem(buffer, 0, BUFFER_SIZE + 1, 0);
	}
	*bytes_read = read(fd, *buffer, BUFFER_SIZE);
	while (*bytes_read > 0)
	{
		if (find_nl(*buffer, 0) > 0)
			break ;
		if (!buffer_reset(line, buffer))
			return (0);
		*bytes_read = read(fd, *buffer, BUFFER_SIZE);
	}
	return (1);
}

char	*end_of_line(char **line, char **buffer)
{
	size_t				buffer_len;

	if (find_nl(*line, 0) > 0)
	{
		leftovers(buffer, line, 0, 0);
		return (*line);
	}
	if (!*buffer)
		return (*line);
	if (find_nl(*buffer, 0) < 0)
		buffer_len = find_nl(*buffer, 1);
	else
		buffer_len = find_nl(*buffer, 0);
	if (buffer_len)
		*line = ft_recalloc(line, (size_t)find_nl(*line, 1) + buffer_len + 1);
	else
		ft_mem(buffer, 0, 0, 1);
	if (!*line)
	{
		if (*buffer)
			ft_mem(buffer, 0, 0, 1);
		return (NULL);
	}
	leftovers(buffer, line, 1, buffer_len);
	return (*line);
}

int	buffer_reset(char **line, char **buffer)
{
	signed long long	buff_len;
	size_t				i;

	buff_len = find_nl(*buffer, 0);
	if (buff_len > 0)
		*line = ft_recalloc(line, find_nl(*line, 1) + buff_len + 1);
	else
		*line = ft_recalloc(line, find_nl(*line, 1) + find_nl(*buffer, 1) + 1);
	if (*line == NULL)
	{
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
	ft_strncat(*line, *buffer, find_nl(*buffer, 0));
	i = 0;
	while (i < BUFFER_SIZE)
		(*buffer)[i++] = 0;
	return (1);
}

void	shift_buffer(char **buffer)
{
	signed long long	len;
	size_t				i;

	if (!*buffer)
		return ;
	len = find_nl(*buffer, 0);
	if (len < 0)
		len = find_nl(*buffer, 1);
	i = 0;
	while ((*buffer)[len])
		(*buffer)[i++] = (*buffer)[len++];
	(*buffer)[i] = 0;
	if (**buffer == 0)
	{
		free(*buffer);
		*buffer = NULL;
	}
	else
	{
		*buffer = ft_recalloc(buffer, len + 1);
		if (!*buffer)
			return ;
		(*buffer)[len] = 0;
	}
}
