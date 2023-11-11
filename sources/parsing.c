/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:46 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/11 18:32:08 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	accessibility_helper(t_data *data)
{
	if (access(data->file_out, F_OK) == -1)
	{
		ft_printf("OUT FILE: could not be found\n%s will be created\n",
		data->file_out);
		data->out_file_fd = open(data->file_out, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	}
	else if (access(data->file_out, W_OK) == 0)
		data->out_file_fd = open(data->file_out, O_WRONLY | O_APPEND);
	else
		to_exit(data, "OUT FILE: Access denied...\n");
	if (data->out_file_fd == -1 || data->in_file_fd == -1)
		to_exit(data, "||ERROR||\nTrouble to open out/input file...\n");
	ft_printf("FILES OK\n");
}

void	accessibility(t_data *data, char *in_file)
{
	ft_printf("\n====||FILE HANDELING||====\n");
	if (!data->limiter)
	{
		if (access(in_file, F_OK) == -1)
			to_exit(data, "IN FILE: could not be found...\n");
		if (access(in_file, R_OK) == -1)
			to_exit(data, "IN FILE: Access denied...\n");
		data->in_file_fd = open(in_file, O_RDONLY);
		accessibility_helper(data);
		return ;
	}
	if (access(data->file_out, F_OK) == -1)
	{
		ft_printf("OUT FILE: could not be found\n%s will be created\n",
		data->file_out);
		data->out_file_fd = open(data->file_out, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	}
	else if (access(data->file_out, W_OK) == 0)
		data->out_file_fd = open(data->file_out, O_WRONLY | O_TRUNC);
	else
		to_exit(data, "OUT FILE: Access denied...\n");
	if (data->out_file_fd == -1)
		to_exit(data, "||ERROR||\nTrouble to open out/input file...\n");
	ft_printf("FILES OK\n");
}

void	read_here_doc(t_data *data)
{
	int		fd[2];
	char	*s;

	if (pipe(fd) == -1)
		to_exit(data, "||ERROR||\nHandeling pipes...\n");
	ft_printf("\nPlease write the content...\n");
	while (1)
	{
		s = get_next_line(STDIN_FILENO);
		if (ft_strncmp(data->limiter, s, ft_strlen(data->limiter)) == 0
			&& ft_strlen(data->limiter) == (ft_strlen(s) - 1))
			break ;
		write(fd[1], s, ft_strlen(s));
		free (s);
	}
	free(s);
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
		to_exit(data, "||ERROR||\nTrouble with allocating memory...\n");
	data->cmds[data->cmd_nbr] = 0;
	while (++i < data->cmd_nbr)
	{
		data->cmds[i] = ft_strdup(av[first_cmd + i]);
		if (!data->cmds[i])
			to_exit(data, "||ERROR||\nTrouble with allocating memory...\n");
	}
	
}

void	parsing(t_data *data, char **av)
{
	accessibility(data, av[1]);
	if (data->limiter)
		read_here_doc(data);
	command_filler(data, av);
}