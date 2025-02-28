/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:25:26 by qacjl             #+#    #+#             */
/*   Updated: 2025/02/28 05:15:51 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_path_from_value(const char *path_value)
{
	char	**splitted_path;
	int		i;

	splitted_path = ft_split(path_value, ':');
	i = 0;
	while (splitted_path[i] != NULL)
	{
		splitted_path[i] = join_and_free(splitted_path[i], "/");
		i = i + 1;
	}
	return (splitted_path);
}

char	*find_path_line(char **envp)
{
	int		i;
	char	*path_line;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
	{
		i = i + 1;
	}
	path_line = ft_strdup(envp[i] + 5);
	return (path_line);
}

char	*get_pwd(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (ft_strncmp(envp[i], "PWD=", 4) != 0)
	{
		i = i + 1;
	}
	path = ft_strdup(envp[i] + 4);
	return (path);
}

int	get_shell_level(char **envp)
{
	int	i;
	int	shlvl;

	i = 0;
	while (ft_strncmp(envp[i], "SHLVL=", 6) != 0)
	{
		i = i + 1;
	}
	shlvl = ft_atoi(envp[i] + 6);
	return (shlvl);
}

char	**split_path(char **envp)
{
	int		i;
	char	**splitted_path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
	{
		i = i + 1;
	}
	splitted_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (splitted_path[i] != NULL)
	{
		splitted_path[i] = join_and_free(splitted_path[i], "/");
		i = i + 1;
	}
	return (splitted_path);
}
