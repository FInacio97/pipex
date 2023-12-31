/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:58:17 by fda-estr          #+#    #+#             */
/*   Updated: 2023/12/09 21:02:05 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initializer(t_data *data, char **av, int ac, char **envp)
{
	data->file_out = ft_strdup(av[ac - 1]);
	data->env = envp;
	data->cmds = NULL;
	data->cmds_paths = NULL;
	data->read_fd = -1;
	data->write_fd = -1;
	data->cmd_arg = NULL;
	data->exit_status = 0;
	if (ft_strncmp("here_doc", av[1], 9) == 0)
	{
		data->limiter = ft_strdup(av[2]);
		data->cmd_nbr = ac - 4;
		data->in_file = NULL;
	}
	else
	{
		data->in_file = ft_strdup(av[1]);
		data->limiter = NULL;
		data->cmd_nbr = ac - 3;
	}
	data->pid = (int *)malloc(sizeof(int) * data->cmd_nbr);
	if (!data->pid)
		to_exit(data, "Error: trouble allocating memory...\n", 0);
}

void	to_exit(t_data *data, char *error, int exit_status)
{
	if (error)
		perror(error);
	if (data->read_fd >= 0)
		close (data->read_fd);
	if (data->write_fd >= 0)
		close (data->write_fd);
	if (data->limiter)
		free (data->limiter);
	if (data->cmds)
		matrix_deleter(data->cmds);
	if (data->file_out)
		free (data->file_out);
	if (data->pid)
		free (data->pid);
	if (data->cmds_paths)
		matrix_deleter(data->cmds_paths);
	if (data->cmd_arg != NULL)
		matrix_deleter(data->cmd_arg);
	if (data->in_file)
		free (data->in_file);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	exit (exit_status);
}

int	to_close(int fd)
{
	if (fd != -1)
		close (fd);
	return (-1);
}

char	*first_word(t_data *data, char *s)
{
	int		i;
	char	*prod;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	prod = malloc(i + 1);
	if (!prod)
		to_exit(data, "Error: Could not allocate memory...\n", 0);
	i = -1;
	while (s[++i] && s[i] != ' ')
		prod[i] = s[i];
	prod[i] = 0;
	return (prod);
}

void	to_exit_2(t_data *data, char *error, char *s1, char *s2)
{
	if (s1)
		free (s1);
	if (s2)
		free (s2);
	to_exit(data, error, 0);
}
