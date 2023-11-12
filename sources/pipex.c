/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:18:52 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/12 16:35:01 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/*Make it so that if one of the child processes fails to execute, the program
 doesnt write anything in the out file. the solution is that the last CP instead
 of writing directly on the file, writes in another pipe. After the parent
 process waits for all CPs to end (with a positive exit status), it reads the
 content of the last pipe and writes it in the out file*/

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if ((ac > 4 && ft_strncmp("here_doc", av[1], 9) != 0)
		|| (ac > 5 && ft_strncmp("here_doc", av[1], 9) == 0))
	{
		initializer(&data, av, ac);
		environment_init(&data, envp);
		parsing(&data, av);
		process_generator(&data);
		to_exit(&data, "\nProgram successfully terminated!\n");		
	}
	else
		// matrix_printer(envp);
		environment_init(&data, envp);
		ft_printf("%s\n", data.env);
		ft_printf("||ERROR||\nnot enough arguments...\n");
	char *arg[] = { "grep", "Estudo", "test.txt", NULL };

	ft_printf("\n\n====COMMAND RUNNING====\n");
			execve("/bin/grep", arg, NULL);
	
}

/*


*/