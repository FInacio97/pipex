/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:46 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/21 20:40:24 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	accessibility(t_data *data, char *in_file)
{
	if (data->limiter == NULL)
	{
		if (access(in_file, F_OK) == -1)
			to_exit(data, "Error: Couldn't find infile...\n", 0);
		if (access(in_file, R_OK) == -1)
			to_exit(data, "Error: Infile: permission denied...\n", 0);
	}
	if (access(data->file_out, F_OK) == -1)
	{
			data->out_file_fd = open(data->file_out, O_WRONLY | O_CREAT
			, S_IRUSR | S_IWUSR);
	}
	if (access(data->file_out, W_OK) == -1)
		to_exit(data, "Error: Outfile: permission denied...\n", 0);
}

void	read_here_doc(t_data *data)
{
	int		fd[2];
	char	*s;

	if (pipe(fd) == -1)
		to_exit(data, "Error: Handeling pipes...\n", 0);
	while (1)
	{
		ft_printf("> ");
		s = get_next_line(STDIN_FILENO);
		if (ft_strncmp(data->limiter, s, ft_strlen(data->limiter)) == 0
			&& ft_strlen(data->limiter) == (ft_strlen(s) - 1))
			break ;
		write(fd[1], s, ft_strlen(s));
		free (s);
	}
	free (s);
	close (fd[1]);
	data->in_file_fd = fd[0];
}

void	command_filler(t_data *data, char **av)
{
	int	first_cmd;
	int	i;

	i = -1;
	if (data->limiter)
		first_cmd = 3;
	else
		first_cmd = 2;
	data->cmds = malloc(sizeof(char *) * (data->cmd_nbr + 1));
	if (!data->cmds)
		to_exit(data, "Error: Trouble with allocating memory...\n", 0);
	data->cmds[data->cmd_nbr] = 0;
	while (++i < data->cmd_nbr)
	{
		if (av[first_cmd + i][0] == 0)
			data->cmds[i] = ft_strdup("' '");
		else
			data->cmds[i] = ft_strdup(av[first_cmd + i]);
		if (!data->cmds[i])
			to_exit(data, "Error: Trouble with allocating memory...\n", 0);
	}
}

void	file_opener(t_data *data, char *in_file)
{
	if (data->limiter == NULL)
	{
		data->in_file_fd = open(in_file, O_RDONLY);
		if (data->in_file_fd == -1)
			to_exit(data, "Error: Trouble open in_file...\n", 0);
		if (data->out_file_fd > 0)
			return;
		data->out_file_fd = open(data->file_out, O_WRONLY | O_TRUNC);
		if (data->out_file_fd == -1)
			to_exit(data, "Error: Trouble open out_file...\n", 0);
		return ;
	}
	if (data->out_file_fd > 0)
		return;
	data->out_file_fd = open(data->file_out, O_WRONLY | O_APPEND);
	if (data->out_file_fd == -1)
		to_exit(data, "Error: Trouble open out file...\n", 0);
}

void	parsing(t_data *data, char **av)
{
	accessibility(data, av[1]);
	if (data->limiter)
		read_here_doc(data);
	command_filler(data, av);
}
