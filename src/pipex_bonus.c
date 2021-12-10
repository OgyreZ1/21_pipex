/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:47:30 by yironmak          #+#    #+#             */
/*   Updated: 2021/12/10 16:58:32 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"
#include "get_next_line.h"

void	process(char *arg, char **envp)
{
	pid_t	parent;
	int		end[2];

	pipe(end);
	parent = fork();
	if (parent < 0)
	{
		perror("Fork: ");
		return ;
	}
	if (parent == 0)
	{
		close(end[0]);
		if (dup2(end[1], STDOUT_FILENO) < 0)
			error("Unable to dup()", NULL);
		execute_cmd(arg, envp);
	}
	else
	{
		close(end[1]);
		if (dup2(end[0], STDIN_FILENO) < 0)
			error("Unable to dup()", NULL);
	}
}

void	last_process(char **argv, char **envp, int argc, int append)
{
	int		file_out;
	pid_t	wait;

	if (!append)
		file_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	else
		file_out = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT);
	if (file_out < 0)
		error("Unable to open file: ", argv[argc - 1]);
	dup2(file_out, STDOUT_FILENO);
	wait = fork();
	if (wait == 0)
		execute_cmd(argv[argc - 2], envp);
	else
		while (argc-- - 4 > 0)
			waitpid(wait, NULL, 0);
}

void	here_doc(char *limiter)
{
	int		file_in;
	char	*line;

	file_in = open("hd_temp", O_WRONLY | O_TRUNC);
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 0);
		line = get_next_line(0);
		if (ft_strlen(line) - 1 == ft_strlen(limiter) && \
			ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break ;
		ft_putstr_fd(line, file_in);
		free(line);
	}
	free(line);
	close(file_in);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		file_in;

	if (argc >= 5)
	{
		i = 1;
		if (argc == 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			here_doc(argv[2]);
			file_in = open("hd_temp", O_RDONLY);
			dup2(file_in, STDIN_FILENO);
			process(argv[3], envp);
			last_process(argv, envp, argc, 1);
			exit(0);
		}
		file_in = open(argv[1], O_RDONLY);
		if (file_in < 0)
			error("Unable to open file: ", argv[1]);
		dup2(file_in, STDIN_FILENO);
		while (++i < argc - 2)
			process(argv[i], envp);
		last_process(argv, envp, argc, 0);
	}
	else
		error("There must be at least 4 arguments", NULL);
}
