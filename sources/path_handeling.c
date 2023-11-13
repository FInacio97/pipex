/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handeling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:51:12 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/13 13:08:19 by fda-estr         ###   ########.fr       */
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

void	path_finder_error(t_data *data, char *cmd_name, char **path_dir, char *env_path)
{
	ft_printf("||ERROR||\nCommand '%s' not found...\n", cmd_name);
	free (cmd_name);
	matrix_deleter(path_dir);
	free (env_path);
	to_exit(data, NULL);
}

void	path_finder(t_data *data, char **path_dir, int i, char *env_path)
{
	int		j;
	char 	*s;
	char	*cmd_name;

	j = -1;
	cmd_name = first_word(data->cmds[i]);
	if (!cmd_name)
		to_exit(data, "||ERROR||\nCould not allocate memory...\n");
	while (path_dir[++j])
	{
		s = ft_strjoin(path_dir[j], "/");
		
		if (!s)
			to_exit_2(data, "||ERROR||\nAllocating mem\n", cmd_name, NULL);
		data->cmds_paths[i] = ft_strjoin(s, cmd_name);
		if (!data->cmds_paths[i])
			to_exit_2(data, "||ERROR||\nCouldnt allocate mem\n", cmd_name, s);
		free (s);
		if (access(data->cmds_paths[i], F_OK) == 0)
		{
			free (cmd_name);
			return ;
		}
		free (data->cmds_paths[i]);
		data->cmds_paths[i] = NULL;
	}
	path_finder_error(data, cmd_name, path_dir, env_path);
}

void	path_handeling(t_data *data)
{
	char	*env_path;
	char	**path_dir;
	int		i;

	i = -1;
	env_path = dir_finder(data);

	if (!env_path)
		to_exit(data, "||ERROR||\nAllocating memory...\n");
	path_dir = ft_split(env_path, ':');
	data->cmds_paths = malloc(sizeof(char *) * (data->cmd_nbr + 1));
	if (!data->cmds_paths)
		to_exit(data, "||ERROR||\nCould not allocate memory...\n");
	data->cmds_paths[data->cmd_nbr] = 0;
	while (data->cmds[++i])
		path_finder(data, path_dir, i, env_path);
	matrix_deleter(path_dir);
	free (env_path);
}