/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:58 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/21 20:01:58 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>

# ifndef LIMIT_ARGS
#  define LIMIT_ARGS 1
# endif

typedef struct s_data
{
	int		in_file_fd;
	int		out_file_fd;
	int		*pid;
	int		read_fd;
	int		write_fd;
	char	**env;
	char	**cmds_paths;
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
void	executor(t_data *data, int i, int fd);
void	wait_loop(t_data *data);
void	process_generator(t_data *data, int i);

/*PATH HANDELING*/
char	*dir_finder(t_data *data);
void	path_finder_error(t_data *data, char *cmd, char **p_dir);
void	path_finder(t_data *data, char **path_dir, int i, int j);
void	path_handeling(t_data *data);

/*UTILS*/
void	initializer(t_data *data, char **av, int ac, char **envp);
void	to_exit(t_data *data, char *error, int exit_status);
int		to_close(int fd);
char	*first_word(char *s);
void	to_exit_2(t_data *data, char *error, char *s1, char *s2);

#endif