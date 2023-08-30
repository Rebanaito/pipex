/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 01:19:51 by ekolosov          #+#    #+#             */
/*   Updated: 2023/07/15 06:43:57 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/pipex.h"

void	clean_pipes(t_pipe *pipes, char **env)
{
	char	**tmp;
	t_pipe	*temp;

	while (pipes)
	{
		if (pipes->path)
			free(pipes->path);
		if (pipes->argv)
		{
			tmp = pipes->argv;
			while (*tmp)
				free(*tmp++);
			free(pipes->argv);
		}
		if (pipes->env != env)
		{
			tmp = pipes->env;
			while (*tmp)
				free(*tmp++);
			free(pipes->env);
		}
		temp = pipes;
		pipes = pipes->next;
		free(temp);
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	error_exit(char *error_message, int exit_code, t_pipe *pipes)
{
	if (pipes)
		perror(pipes->argv[0]);
	else
		perror(error_message);
	if (exit_code != -1)
		exit(exit_code);
}

char	*slash(char *str)
{
	while (*str)
		str++;
	while (*str != '/')
		str--;
	return (str + 1);
}
