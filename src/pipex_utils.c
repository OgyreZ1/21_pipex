/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:47:26 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/10 17:30:30 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"
#include <stdio.h>

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

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
		{
			free_arr(strs);
			return (path);
		}
		free(path);
	}
	free_arr(strs);
	return (NULL);
}

void	error(char *message, char *cmd)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	if (cmd)
		ft_putstr_fd(cmd, 2);
	ft_putchar_fd('\n', 2);
	exit(-1);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_name;

	args = ft_split(cmd, ' ');
	cmd_name = ft_strjoin("/", args[0]);
	if (execve(find_path(cmd_name, envp), args, envp) == -1)
	{
		free(cmd_name);
		free_arr(args);
		error("Command not found: ", cmd);
	}
	free_arr(args);
	free(cmd_name);
}
