/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:42:56 by ekolosov          #+#    #+#             */
/*   Updated: 2023/07/15 07:42:10 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include	"libft/libft.h"
# include	<errno.h>
# include	<sys/wait.h>
# include	<fcntl.h>

typedef struct s_pipe
{
	char			*path;
	char			**argv;
	char			**env;
	int				infd;
	struct s_pipe	*next;
}	t_pipe;

int		parser(t_pipe **pipes, int argc, char **argv, char **env);
void	clean_pipes(t_pipe *pipes, char **env);
void	free_split(char **split);
int		parse_env(t_pipe *new, char **split);
int		parse_path(t_pipe *new, char **split);
int		parse_argv(t_pipe *new, char **split);
void	error_exit(char *error_message, int exit_code, t_pipe *pipes);
void	open_infile(t_pipe *pipes, char **argv);
int		open_outfile(char *path, char *infile, t_pipe *pipes, char **env);
void	heredoc(t_pipe *pipes, char **argv);
char	*slash(char *str);

#endif	//	PIPEX_H