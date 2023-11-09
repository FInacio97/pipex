/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:58 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/09 20:06:53 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
	char	*file_out;
	char	**cmds;
	char	**content;
	char	*limiter;
	int		cmd_nbr;
	int		out_flag;
}				t_data;

/*PARSING*/
void	reader(t_data *data, char *file);
void	read_here_doc(t_data *data);
void	command_filler(t_data *data, char **av);
void	accessibility(t_data *data, char *in_file);
void	parsing(t_data *data, char **av);

/*UTILS*/
void	initializer(t_data *data, char **av, int ac);
void	to_exit(t_data *data, char *error);
void	writer(t_data *data);



#endif