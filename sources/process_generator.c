/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:36:37 by fda-estr          #+#    #+#             */
/*   Updated: 2023/12/10 14:51:52 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	executor(t_data *data, int i, int fd)
{
	char	*s;
	
	if (!data->limiter && i == 0)
		redirect_in(data, fd);
	if (i == data->cmd_nbr - 1)
		redirect_out(data, fd);
	// printf("in: %d\tout: %d\n", fcntl(data->read_fd, F_GETFL), fcntl(data->write_fd, F_GETFL));
	dup2(data->read_fd, STDIN_FILENO);
	dup2(data->write_fd, STDOUT_FILENO);
	to_close(data->read_fd);
	to_close(data->write_fd);
	to_close(fd);
	execve(data->cmds_paths[i], data->cmd_arg, data->env);
	s = ft_strjoin("Could not find command: ", data->cmds[i]);
	s = ft_strjoin_free(s, "\n", 1);
	perror(s);
	free (s);
	to_close(STDIN_FILENO);
	to_close(STDOUT_FILENO);
	to_exit(data, NULL, 127);
}

void	wait_loop(t_data *data)
{
	int		j;
	pid_t	pid;

	j = -1;
	while (++j < data->cmd_nbr)
	{
		pid = wait(&data->exit_status);
		// if (data->exit_status == 0)
		// 	// ft_printf("Finish execution of child process %d\n", pid);
		// else
		// 	// ft_printf("Error: Could not execute command(%d)\texit status: %d\n",
		// 		pid, data->exit_status);
		(void) pid;
	}
}

void	process_generator(t_data *data, int i)
{
	int	fd[2];

	while (++i < data->cmd_nbr)
	{
		data->cmd_arg = ft_split(data->cmds[i], ' ');
		if (i < data->cmd_nbr - 1)
		{
			if (pipe(fd) == -1)
				to_exit(data, "Error: Handeling pipes...\n", 0);
			data->write_fd = fd[1];
		}
		data->pid[i] = fork();
		if (data->pid[i] == 0)
			executor(data, i, fd[0]);
		if (data->limiter && i == 0)
			to_close(data->read_fd);
		to_close(data->read_fd);
		to_close(data->write_fd);
		if (i < data->cmd_nbr - 1)
			data->read_fd = fd[0];
		matrix_deleter(data->cmd_arg);
		data->cmd_arg = NULL;
	}
	wait_loop(data);
}

/*
			read_fd		write_fd
	cmd1		x			x
	cmd2		x
	cmd3

*/