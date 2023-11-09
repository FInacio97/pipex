/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:58:17 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/09 17:12:05 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initializer(t_data *data, char **av, int ac)
{
	data->file_out = ft_strdup(av[ac - 1]);
	data->cmds = NULL;
	data->content = NULL;
	data->out_flag = 0;
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
}

void	to_exit(t_data *data, char *error)
{
	ft_printf("%s", error);
	if (data->limiter)
		free (data->limiter);
	if (data->cmds)
	 {
		matrix_deleter(data->cmds);
		ft_printf("Commands freed...\n");
	 }
	if (data->content)
	{
		matrix_deleter(data->content);
		ft_printf("Content freed...\n");
	}
	if (data->file_out)
		free (data->file_out);

}

void	writer(t_data *data)
{
	
}
