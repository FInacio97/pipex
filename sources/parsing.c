/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:46 by fda-estr          #+#    #+#             */
/*   Updated: 2023/12/10 12:35:05 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"	

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
	data->read_fd = fd[0];
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

void	parsing(t_data *data, char **av)
{
	if (data->limiter)
		read_here_doc(data);
	command_filler(data, av);
}
