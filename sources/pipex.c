/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:52 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/13 17:29:31 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if ((ac > 4 && ft_strncmp("here_doc", av[1], 9) != 0)
		|| (ac > 5 && ft_strncmp("here_doc", av[1], 9) == 0))
	{
		initializer(&data, av, ac, envp);
		parsing(&data, av);
		path_handeling(&data);
		file_opener(&data, av[1]);
		process_generator(&data, -1);
		to_exit(&data, "\nProgram successfully terminated!\n");
	}
	else
		ft_printf("||ERROR||\nnot enough arguments...\n");
}
