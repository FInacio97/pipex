/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:58:17 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/11 23:00:40 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initializer(t_data *data, char **av, int ac)
{
	data->file_out = ft_strdup(av[ac - 1]);
	data->cmds = NULL;
	data->in_file_fd = -1;
	data->out_file_fd = -1;
	if (ft_strncmp("here_doc", av[1], 9) == 0)
	{
		data->limiter = ft_strdup(av[2]);
		data->cmd_nbr = ac - 4;
	}
	else
	{
		data->limiter = NULL;
		data->cmd_nbr = ac - 3;
	}
	data->pid = (int *)malloc(sizeof(int) * data->cmd_nbr);
	if (!data->pid)
		to_exit(data, "||ERROR||\n trouble allocating memory...\n");
}

void	to_exit(t_data *data, char *error)
{
	ft_printf("%s", error);
	if (data->read_fd >= 0)
		close (data->read_fd);
	if (data->write_fd >= 0)
		close (data->write_fd);
	if (data->in_file_fd >= 0)
		close (data->in_file_fd);
	if (data->out_file_fd >= 0)
		close (data->out_file_fd);
	if (data->limiter)
		free (data->limiter);
	if (data->cmds)
		matrix_deleter(data->cmds);
	if (data->file_out)
		free (data->file_out);
	if (data->pid)
		free (data->pid);
	if (data->cmd_arg)
		free (data->cmd_arg);
	if (data->env)
		free (data->env);
	exit (0);
}

int	to_close(int fd)
{
	close (fd);
	return (-1);
}

void	environment_init(t_data *data, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	}
	data->env = ft_strdup(envp[i]);
}