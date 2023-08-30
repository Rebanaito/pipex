/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:34:56 by ekolosov          #+#    #+#             */
/*   Updated: 2023/07/15 08:27:48 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/pipex.h"

char	*read_stdin(char *limiter)
{
	char	*buff[3];

	buff[2] = (char *)ft_calloc(1, sizeof(char));
	if (!buff[2])
		error_exit("Malloc failure", 1, NULL);
	ft_putstr("pipe heredoc> ");
	buff[0] = get_next_line(0);
	if (!buff[0])
		error_exit("Malloc failure", 1, NULL);
	while (ft_strcmp(limiter, buff[0]) != -10)
	{
		ft_putstr("pipe heredoc> ");
		buff[1] = ft_strjoin(buff[2], buff[0]);
		if (!buff[1])
			error_exit("Malloc failure", 1, NULL);
		free(buff[0]);
		free(buff[2]);
		buff[2] = buff[1];
		buff[0] = get_next_line(0);
		if (!buff[0])
			error_exit("Malloc failure", 1, NULL);
	}
	free(buff[0]);
	return (buff[2]);
}

void	heredoc(t_pipe *pipes, char **argv)
{
	int		fd[2];
	char	*buffer;

	if (pipe(fd) < 0)
		error_exit("Pipe error", 1, NULL);
	buffer = read_stdin(argv[2]);
	ft_putstr_fd(buffer, fd[1]);
	close(fd[1]);
	pipes->infd = fd[0];
	free(buffer);
}

int	forking(t_pipe *pipes, int fd)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		error_exit("Fork error", 1, pipes);
	if (!pid)
	{
		if (pipes->path == NULL)
			exit(0);
		if (access(pipes->path, X_OK))
		{
			ft_putstr_fd(slash(pipes->path), STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit(1);
		}
		if (pipes->infd > 0 && (dup2(pipes->infd, 0) < 0 || dup2(fd, 1) < 0))
			error_exit("Dup error", 1, pipes);
		if (execve(pipes->path, pipes->argv, pipes->env) < 0)
			error_exit(NULL, EXIT_FAILURE, pipes);
	}
	return (pid);
}

int	execute_cmds(t_pipe *pipes, int argc, char **argv, char **env)
{
	int		fd[2];
	int		code;
	t_pipe	*tmp;

	code = 0;
	tmp = pipes;
	open_infile(pipes, argv);
	while (pipes->next)
	{
		if (pipe(fd) < 0)
			error_exit("Pipe error", 1, pipes);
		waitpid(forking(pipes, fd[1]), &code, 0);
		close(fd[1]);
		if (pipes->infd >= 0)
			close(pipes->infd);
		pipes = pipes->next;
		pipes->infd = fd[0];
	}
	waitpid(forking(pipes, open_outfile(argv[argc - 1], argv[1], tmp, env)),
		&code, 0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	*pipes;

	pipes = NULL;
	if (parser(&pipes, argc, argv, env))
		return (1);
	execute_cmds(pipes, argc, argv, env);
	clean_pipes(pipes, env);
	return (0);
}
