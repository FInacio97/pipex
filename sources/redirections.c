/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:11:50 by fda-estr          #+#    #+#             */
/*   Updated: 2023/12/10 14:59:39 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_in(t_data *data, int fd)
{
	if (access(data->in_file, F_OK) == -1)
	{
		to_close(fd);
		to_exit(data, "Error: Couldn't find infile...\n", 1);
	}
	if (access(data->in_file, R_OK) == -1)
	{
		to_close(fd);
		to_exit(data, "Error: Infile: permission denied...\n", 1);
	}
	data->read_fd = open(data->in_file, O_RDONLY);
	if (data->read_fd == -1)
	{
		to_close(fd);
		to_exit(data, "Error: Trouble open in_file...\n", 1);
	}
}

void	redirect_out(t_data *data, int fd)
{
	if (access(data->file_out, F_OK) == -1)
	{
		data->write_fd = open(data->file_out, O_WRONLY | O_CREAT,
				S_IRUSR | S_IWUSR);
		return ;
	}
	if (access(data->file_out, W_OK) == -1)
	{
		to_close(fd);
		to_exit(data, "Error: Outfile: permission denied...\n", 1);
	}
	if (!data->limiter)
		data->write_fd = open(data->file_out, O_WRONLY | O_TRUNC);
	else
		data->write_fd = open(data->file_out, O_WRONLY | O_APPEND);
	if (data->write_fd == -1)
	{
		to_close(fd);
		to_exit(data, "Error: Trouble open out file...\n", 1);
	}
}
