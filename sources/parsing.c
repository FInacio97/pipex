/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:46 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/12 16:21:11 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	accessibility(t_data *data, char *in_file)
{
	if (data->limiter == NULL)
	{
		ft_printf("yooo\n");
		if (access(in_file, F_OK) == -1)
			to_exit(data, "||ERROR||\nCouldn't find infile...\n");
		if (access(in_file, R_OK) == -1)
			to_exit(data, "||ERROR||\nInfile: permission denied...\n");
	}
	if (access(data->file_out, F_OK) == -1)
			to_exit(data, "||ERROR||\nCouldn't find outfile...\n");
		if (access(data->file_out, W_OK) == -1)
			to_exit(data, "||ERROR||\nOutfile: permission denied...\n");
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

void	file_opener(t_data *data, char *in_file)
{
	if (data->limiter == NULL)
	{
		data->in_file_fd = open(in_file, O_RDONLY);
		if (data->in_file_fd == -1)
		to_exit(data, "||ERROR||\nTrouble open in_file...\n");
		data->out_file_fd = open(data->file_out, O_WRONLY | O_TRUNC);
		if (data->out_file_fd == -1)
		to_exit(data, "||ERROR||\nTrouble open out_file...\n");
		return ;
	}
	data->out_file_fd = open(data->file_out, O_WRONLY | O_APPEND);
	if (data->out_file_fd == -1)
		to_exit(data, "||ERROR||\nTrouble open out file...\n");
}

void	parsing(t_data *data, char **av)
{
	accessibility(data, av[1]);
	if (data->limiter)
		read_here_doc(data);
	command_filler(data, av);
	file_opener(data, av[1]);
}