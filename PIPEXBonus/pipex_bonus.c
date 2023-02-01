/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:59:38 by tpicoule          #+#    #+#             */
/*   Updated: 2023/02/01 10:51:55 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
//#include <signal.h>

void    funkchild(void)
{
    
    printf("cacaprout\n");
    exit(1);
}

int	main(int argc, char **argv, char **env)
{
    t_pipex	*var;
	int		file1;
	int		file2;
	int		i;
    //int     j;
	
    var = malloc(sizeof(*var));
	file1 = open(argv[1], O_RDONLY, 0777);
	file2 = open(argc[argv[argc - 3]], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup2(file1, STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	i = 0;
    //j = argc - 2;
	while (i < (argc - 3))
	{
		var->pid = fork();
		if (var->pid == -1)
            return (printf("CACA"));
        if (var->pid == 0)
            funkchild();
        i++;
	}
    waitpid(-1, NULL, 0);
    return (0);
}
