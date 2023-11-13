/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:36:37 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/13 17:25:21 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	executor(t_data *data, int i)
{
	char	*s;

	dup2(data->read_fd, STDIN_FILENO);
	dup2(data->write_fd, STDOUT_FILENO);
	to_close(data->read_fd);
	to_close(data->write_fd);
	execve(data->cmds_paths[i], data->cmd_arg, data->env);
	exit (1);
}

void	wait_loop(t_data *data)
{
	int		j;
	int		exit_status;
	pid_t	pid;

	j = -1;
	while (++j < data->cmd_nbr)
	{
		pid = wait(&exit_status);
		if (exit_status == 1)
			ft_printf("||ERROR||\n%s could not execute\n", pid);
		else
			ft_printf("Finish execution of child process %d\n", pid);
	}
}

void	process_generator(t_data *data, int i)
{
	int	fd[2];

	data->read_fd = data->in_file_fd;
	while (++i < data->cmd_nbr)
	{
		data->cmd_arg = ft_split(data->cmds[i], ' ');
		if (i < data->cmd_nbr - 1)
		{
			if (pipe(fd) == -1)
				to_exit(data, "||ERROR||\nHandeling pipes...\n");
			data->write_fd = fd[1];
		}
		else
			data->write_fd = data->out_file_fd;
		data->pid[i] = fork();
		if (data->pid[i] == 0)
			executor(data, i);
		data->read_fd = to_close(data->read_fd);
		data->write_fd = to_close(data->write_fd);
		if (i < data->cmd_nbr - 1)
			data->read_fd = fd[0];
		matrix_deleter(data->cmd_arg);
		data->cmd_arg = NULL;
	}
	wait_loop(data);
}
