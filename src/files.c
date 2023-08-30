/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 05:42:32 by ekolosov          #+#    #+#             */
/*   Updated: 2023/07/15 07:42:16 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/pipex.h"

void	open_infile(t_pipe *pipes, char **argv)
{
	if (!ft_strcmp(argv[1], "here_doc"))
		heredoc(pipes, argv);
	else
		pipes->infd = open(argv[1], O_RDONLY);
	if (pipes->infd < 0)
	{
		free(pipes->path);
		pipes->path = NULL;
		error_exit(argv[1], -1, NULL);
	}
}

int	open_outfile(char *path, char *infile, t_pipe *pipes, char **env)
{
	int	fd;

	if (!ft_strcmp(infile, "here_doc"))
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0000644);
	if (fd < 0)
	{
		clean_pipes(pipes, env);
		error_exit(path, 1, NULL);
	}
	return (fd);
}
