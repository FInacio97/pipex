/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handeling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:51:12 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/21 19:52:02 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*dir_finder(t_data *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
	{
		if (ft_strncmp(data->env[i], "PATH=", 5) == 0)
			break ;
	}
	return (ft_strdup(data->env[i] + 5));
}

void	path_finder_error(t_data *data, char *cmd, char **p_dir)
{

	// perror("Error: Command '%s' not found...\n", cmd);
	free (cmd);
	(void) data;
	(void) p_dir;
	// to_exit(data, NULL, 0);
}

void	path_finder(t_data *data, char **path_dir, int i, int j)
{
	char	*s;
	char	*cmd_name;

	cmd_name = first_word(data->cmds[i]);
	if (!cmd_name)
		to_exit(data, "Error: Could not allocate memory...\n", 0);
	while (path_dir[++j])
	{
		s = ft_strjoin(path_dir[j], "/");
		if (!s)
			to_exit_2(data, "Error: Allocating mem\n", cmd_name, NULL);
		data->cmds_paths[i] = ft_strjoin(s, cmd_name);
		if (!data->cmds_paths[i])
			to_exit_2(data, "Error: Couldnt allocate mem\n", cmd_name, s);
		free (s);
		if (access(data->cmds_paths[i], F_OK) == 0)
		{
			free (cmd_name);
			return ;
		}
		free (data->cmds_paths[i]);
		data->cmds_paths[i] = NULL;
	}
	if (data->cmds_paths[i] == NULL)
		data->cmds_paths[i] = ft_strdup("KO");
	path_finder_error(data, cmd_name, path_dir);
}

void	path_handeling(t_data *data)
{
	char	*env_path;
	char	**path_dir;
	int		i;

	i = -1;
	env_path = dir_finder(data);
	if (!env_path)
		to_exit(data, "Error: Allocating memory...\n", 0);
	path_dir = ft_split(env_path, ':');
	free (env_path);
	data->cmds_paths = malloc(sizeof(char *) * (data->cmd_nbr + 1));
	if (!data->cmds_paths)
		to_exit(data, "Error: Could not allocate memory...\n", 0);
	data->cmds_paths[data->cmd_nbr] = 0;

	while (data->cmds[++i])
		path_finder(data, path_dir, i, -1);
	matrix_deleter(path_dir);
}
