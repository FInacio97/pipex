/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:52 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/22 17:19:27 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if ((LIMIT_ARGS == 1 && ac != 5) || ac < 5)
	{
		perror("Error: Wrong number of arguments...\n");
		exit(0);
	}
	if (LIMIT_ARGS == 0 && ((ac < 5 && ft_strncmp("here_doc", av[1], 9) != 0)
		|| (ac < 6 && ft_strncmp("here_doc", av[1], 9) == 0)))
	{
	perror("Error: Wrong number of arguments here...\n");
		exit(0);
	}
	initializer(&data, av, ac, envp);
	parsing(&data, av);
	path_handeling(&data);
	file_opener(&data, av[1]);
	process_generator(&data, -1);
	ft_printf("\nProgram successfully terminated!\n");
	to_exit(&data, NULL, data.exit_status);
}
