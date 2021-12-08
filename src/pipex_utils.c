/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:47:26 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/08 18:48:38 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*find_path(char	*cmd_name, char **envp)
{
	int		i;
	char	**strs;
	char	*path;

	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[++i], "PATH", 4) == 0)
			break ;
	strs = ft_split(envp[i] + 5, ':');
	i = -1;
	while (strs[++i])
	{
		path = ft_strjoin(strs[i], cmd_name);
		if (access(ft_strjoin(strs[i], cmd_name), F_OK) == 0)
			return (path);
		else
			free(path);
	}
	return (NULL);
}

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_name;

	args = ft_split(cmd, ' ');
	cmd_name = ft_strjoin("/", args[0]);
	if (execve(find_path(cmd_name, envp), args, envp) == -1)
		error();
}
