/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekolosov <ekolosov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 06:41:56 by ekolosov          #+#    #+#             */
/*   Updated: 2023/07/13 06:24:04 by ekolosov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/pipex.h"

int	has_eq(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=' && i && str[i + 1])
			return (1);
	}
	return (0);
}

int	count_env(char **env, char **split)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (split[++i])
	{
		if (has_eq(split[i]))
		{
			if (!env)
				count++;
			else
			{
				env[count] = ft_strdup(split[i]);
				if (!env[count++])
				{
					free_split(env);
					return (-1);
				}
			}
		}
	}
	return (count);
}

int	parse_env(t_pipe *new, char **split)
{
	char	**env;
	int		count;

	env = NULL;
	count = count_env(NULL, split);
	if (!count)
		return (0);
	env = (char **)malloc(sizeof(char *) * (count + 1));
	if (!env)
		return (1);
	env[count] = NULL;
	if (count_env(env, split) == -1)
		return (1);
	new->env = env;
	return (0);
}

int	parse_path(t_pipe *new, char **split)
{
	new->path = ft_strjoin("/usr/bin/", split[0]);
	if (!(new->path))
		error_exit("Malloc error", 1, NULL);
	return (0);
}

int	parse_argv(t_pipe *new, char **split)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (split[++i])
		if (!has_eq(split[i]))
			count++;
	new->argv = (char **)malloc(sizeof(char *) * (count + 1));
	if (!(new->argv))
		error_exit("Malloc error", 1, NULL);
	(new->argv)[count] = NULL;
	i = -1;
	count = -1;
	while (split[++i])
	{
		if (!has_eq(split[i]))
		{
			(new->argv)[++count] = ft_strdup(split[i]);
			if ((new->argv)[count] == NULL)
				error_exit("Malloc error", 1, NULL);
		}
	}
	return (0);
}
