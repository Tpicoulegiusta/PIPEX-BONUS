/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:59:38 by tpicoule          #+#    #+#             */
/*   Updated: 2023/02/01 16:16:41 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
//#include <signal.h>

void    funkchild(void)
{
    dup2(var->pipefd[1], STDOUT_FILENO);
	close(var->pipefd[1]);
	close(var->pipefd[0]);
	var->argu = funct_split();
    printf("cacaprout\n");
    exit(1);
}

int	main(int argc, char **argv, char **env)
{
	//LA FUTUR STRUCTURE
	int		file1;
	int		file2;
	int		cmds;
	int		pid;
	int		**pipefds;
	int		nbpipes;

	cmds = argc - 3;
	nbpipes = cmds - 1;
	
	//ON GERE LES OPEN ET LES FILES
	file1 = open(argv[1], O_RDONLY, 0777);
	file2 = open(argc[argv[argc - 3]], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup2(file1, STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	
	//ON CREER LES PIPES
	while (nbpipes > 0)
	{
		
	}
    waitpid(-1, NULL, 0);
    return (0);
}
