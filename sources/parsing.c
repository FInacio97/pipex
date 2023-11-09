/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:46 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/09 22:30:18 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	accessibility(t_data *data, char *in_file)
{
	if (!data->limiter)
	{
		if (access(in_file, F_OK) == -1)
			to_exit(data, "IN FILE: could not be found...\n");
		if (access(in_file, R_OK) == 0)
			ft_printf("IN FILE: Access granted!\n");
		else
			to_exit(data, "IN FILE: Access denied...\n");
	}
	if (access(data->file_out, F_OK) == -1)
	{
		ft_printf("OUT FILE: could not be found\n%s will be created\n",
		data->file_out);
		data->out_flag = 1;
	}
	else if (access(data->file_out, W_OK) == 0)
		ft_printf("OUT FILE: Access granted!\n");
	else
		to_exit(data, "OUT FILE: Access denied...\n");
}

void	reader(t_data *data, char *file)
{
	int		fd;
	char	*s;
	char 	*train;
	
	fd = open (file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("||ERROR||\nInput file not found...\n");
		exit (0);
	}
	train = ft_strdup("");
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		train = ft_strjoin_free(train, s, 3);
	}
	data->content = ft_split(train, '\n');
	if (!data->content)
		to_exit(data, "||ERROR||\nTrouble with allocating memory...\n");
	free (train);
	close (fd);
}

void	read_here_doc(t_data *data)
{
	char	*s;
	char 	*train;

	s = NULL;
	train = ft_strdup("");
	while (1)
	{
		s = get_next_line(STDIN_FILENO);
		if (ft_strncmp(data->limiter, s, ft_strlen(data->limiter)) == 0
			&& ft_strlen(data->limiter) == (ft_strlen(s) - 1))
			break ;
		train = ft_strjoin_free(train, s, 3);
	}
	free(s);
	data->content = ft_split(train, '\n');
	free (train);
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
	else
		reader(data, av[1]);
	command_filler(data, av);
}