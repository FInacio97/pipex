/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:58 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/12 14:58:15 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct s_data
{
	int		in_file_fd;
	int		out_file_fd;
	int		*pid;
	int		read_fd;
	int		write_fd;
	char	*env;

	char	*file_out;
	char	**cmds;
	char	**cmd_arg;
	char	*limiter;
	int		cmd_nbr;
}				t_data;

/*PARSING*/
void	accessibility(t_data *data, char *in_file);
void	read_here_doc(t_data *data);
void	command_filler(t_data *data, char **av);
void	file_opener(t_data *data, char *in_file);
void	parsing(t_data *data, char **av);

/*PROCESS GENERATOR*/
void	executor(t_data *data, int i);
void	process_generator(t_data *data);

/*UTILS*/
void	initializer(t_data *data, char **av, int ac);
void	to_exit(t_data *data, char *error);
int		to_close(int fd);
void	environment_init(t_data *data, char **envp);



#endif