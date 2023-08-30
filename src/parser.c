/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 01:12:04 by ekolosov          #+#    #+#             */
/*   Updated: 2023/07/13 06:38:48 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/pipex.h"

int	cmds_parsing(t_pipe *new, char **split, char **env)
{
	new->infd = 0;
	new->next = NULL;
	new->env = env;
	new->argv = NULL;
	new->path = NULL;
	if (parse_env(new, split))
		return (1);
	if (parse_path(new, split))
		return (1);
	if (parse_argv(new, split))
		return (1);
	return (0);
}

int	cmds(t_pipe **pipes, char *av, char **env)
{
	t_pipe	*new;
	t_pipe	*tmp;
	char	**split;

	new = (t_pipe *)malloc(sizeof(t_pipe));
	if (!new)
		return (1);
	split = ft_split_quotes(av, ' ');
	if (!split)
		error_exit("Malloc error", 1, NULL);
	if (!(*pipes))
		*pipes = new;
	else
	{
		tmp = *pipes;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	if (cmds_parsing(new, split, env))
		error_exit("Malloc error", 1, NULL);
	free_split(split);
	return (0);
}

int	parser(t_pipe **pipes, int argc, char **argv, char **env)
{
	int	i;

	if (argc < 5 || (argc < 6 && !ft_strcmp(argv[1], "here_doc")))
		error_exit("Syntax error", 1, NULL);
	i = 2;
	if (!ft_strcmp(argv[1], "here_doc"))
		i++;
	while (i < argc - 1)
	{
		if (cmds(pipes, argv[i++], env))
		{
			clean_pipes(*pipes, env);
			return (1);
		}
	}
	return (0);
}
