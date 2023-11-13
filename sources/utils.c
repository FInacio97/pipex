/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:58:17 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/13 00:13:55 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initializer(t_data *data, char **av, int ac, char **envp)
{
	data->file_out = ft_strdup(av[ac - 1]);
	data->env = envp;
	data->cmds = NULL;
	data->cmds_paths = NULL;
	data->in_file_fd = -1;
	data->out_file_fd = -1;
	data->read_fd = -1;
	data->write_fd = -1;
	data->cmd_arg = NULL;
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
	if (error)
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
	if (data->cmds_paths)
		matrix_deleter(data->cmds_paths);
	if (data->cmd_arg != NULL)
		matrix_deleter(data->cmd_arg);
	exit (0);
}

int	to_close(int fd)
{
	close (fd);
	return (-1);
}

char	*first_word(char *s)
{
	int	i;
	char *prod;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	prod = malloc(i + 1);
	if (!prod)
		return (NULL);
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
	to_exit(data, error);
}