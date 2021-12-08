/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:13:19 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/08 19:15:22 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int end[2])
{
	int	file_in;

	printf("child\n");
	file_in = open(argv[1], O_RDONLY);
	dup2(file_in, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	execute_cmd(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int end[2])
{
	int	file_out;

	printf("parent\n");
	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	dup2(end[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(end[1]);
	execute_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		end[2];
	pid_t	parent;
	int		i;

	if (argc == 5)
	{
		pipe(end);
		parent = fork();
		if (parent < 0)
		{
			perror("Fork: ");
			return (-1);
		}
		if (parent == 0)
			child_process(argv, envp, end);
		else
		{
			parent_process(argv, envp, end);
			waitpid(parent, NULL, 0);
		}
	}
}
