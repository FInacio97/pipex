/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:36:37 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/11 23:05:47 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	executor(t_data *data)
{
	dup2(data->read_fd, STDIN_FILENO);
	dup2(data->write_fd, STDOUT_FILENO);
	to_close(data->read_fd);
	to_close(data->write_fd);
	// execve()
}
void	process_generator(t_data *data)
{
	int	fd[2];
	int	i;

	i = -1;
	data->read_fd = data->in_file_fd;
	while (++i < data->cmd_nbr)
	{
		data->cmd_arg = ft_split(data->cmds[i], ' ');
		if (i == data->cmd_nbr)
			data->write_fd = data->out_file_fd;
		else
		{
			if (pipe(fd) == -1)
				to_exit(data, "||ERROR||\nHandeling pipes...\n");
			data->write_fd = fd[1];
		}
		
		data->pid[i] = fork();
		if (data->pid[i] == 0)
			executor(data);
		data->read_fd = to_close(data->read_fd);
		data->write_fd = to_close(data->write_fd);
		if (i < data->cmd_nbr)
			data->read_fd = fd[0];
		free (data->cmd_arg);
	}
}