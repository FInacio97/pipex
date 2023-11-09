/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:52 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/09 17:40:35 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/*DON'T FORGET: if you're supposed to use here_doc as input, you are supposed
NOT to overwrite the file*/

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if ((ac > 4 && ft_strncmp("here_doc", av[1], 9) != 0)
		|| (ft_strncmp("here_doc", av[1], 9) == 0 && ac > 5))
	{
		initializer(&data, av, ac);
		parsing(&data, av);
		printf("==||CONTENT||==\n");
		matrix_printer(data.content);
		printf("\n==||COMMANDS||==\n");
		matrix_printer(data.cmds);
		to_exit(&data, "\nProgram successfully terminated!\n");		
	}
	else
		matrix_printer(envp);
		// ft_printf("||ERROR||\nnot enough arguments...\n");
	
}