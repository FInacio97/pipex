/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:36:37 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/12 22:56:41 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	executor(t_data *data, int i)
{
	char *s;

	dup2(data->read_fd, STDIN_FILENO);
	dup2(data->write_fd, STDOUT_FILENO);
	to_close(data->read_fd);
	to_close(data->write_fd);
	execve(data->cmds_paths[i], data->cmd_arg, data->env);
	exit (1);
	// sleep(i * 1);
	// while (1)
	// {
	// 	s = get_next_line(STDIN_FILENO);
	// 	if (!s)
	// 		break ;
	// 	write (STDOUT_FILENO, s, ft_strlen(s));
	// 	free (s);
	// }
	// exit (0);
}

void	wait_loop(t_data *data)
{
	int	j;
	int	exit_status;
	pid_t pid;

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

void	file_writer(t_data *data)
{
	char *s;

	while (1)
	{
		s = get_next_line(data->read_fd);
		if (!s)
			break ;
		write(data->out_file_fd, s, ft_strlen(s));
		free (s);
	}
	to_close(data->read_fd);
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
		if (pipe(fd) == -1)
			to_exit(data, "||ERROR||\nHandeling pipes...\n");
		data->write_fd = fd[1];
		
		data->pid[i] = fork();
		if (data->pid[i] == 0)
			executor(data, i);
		data->read_fd = to_close(data->read_fd);
		data->write_fd = to_close(data->write_fd);
		data->read_fd = fd[0];
		matrix_deleter(data->cmd_arg);
		data->cmd_arg = NULL;
	}
	wait_loop(data);
	file_writer(data);

	


	
}