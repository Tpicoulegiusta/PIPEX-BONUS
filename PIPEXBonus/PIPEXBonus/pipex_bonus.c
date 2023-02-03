/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:59:38 by tpicoule          #+#    #+#             */
/*   Updated: 2023/02/03 14:34:14 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
//#include <signal.h>

/* void    funkchild(void)
{
    dup2(var->pipefd[1], STDOUT_FILENO);
	close(var->pipefd[1]);
	close(var->pipefd[0]);
	var->argu = funct_split();
    printf("cacaprout\n");
    exit(1);
} */

int	main(int argc, char **argv, char **env)
{
	/* //LA FUTUR STRUCTURE
	int		cmds;
	int		pid;
	int		**pipefds;  //A MALLOC
	int		nbpipes;
	int		pid[cmds];
	char	**argu;
	char	**argu2;
	char	*path;
	int		pid2;
 */
	t_pipex	*value;
	int		file1;
	int		file2;
	int		i;
	int		j;

	i = 0;
	value = malloc(sizeof(*value));
		if (!value)
			return (0);
	int		pid[value->cmds];
	value->cmds = argc - 3;
	value->nbpipes = value->cmds - 1;
	j = 2;
	value->pipefds = malloc(sizeof(char *) * (2 + 1));
		if (!value->pipefds)
			return (0);
	
		if (argc < 0)
	{
		perror("ERROR too few args or too much");
		exit(EXIT_FAILURE);
	}
	
	//ON GERE LES OPEN ET LES FILES
	file1 = open(argv[1], O_RDONLY, 0777);
	file2 = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup2(file1, STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);

	//ON CREER LES PIPES
	j = 0;
	while (value->nbpipes > 0)
	{
		pipe(value->pipefds[i]);
		if (pipe(value->pipefds[i]) == -1)
			return (1);
		i++;
		value->nbpipes--;
	}
	i = 1;	
	//ON CREER LES ENFANTS(INCHALLAH ON LES TUES)
    
    value->pid = fork();
    if (value->pid < 0)
        return (3);
    if (value->pid == 0)
    {
        dup2(value->pipefds[i][1], STDOUT_FILENO);
        close(value->pipefds[i][1]);
        close(value->pipefds[i][0]);
        value->argu = funct_split(argv[j], ' ');
        value->path = ft_find_path(env, value->argu[0], value);
        execve(value->path, value->argu[i], env);
        exit(EXIT_SUCCESS);
        j++;
    }
    
	while (i != value->cmds - 1)
	{
		value->pid = fork();
		if (value->pid < 0)
			return (2);
		if (value->pid == 0)
		{
			dup2(value->pipefds[i][1], STDOUT_FILENO);
			close(value->pipefds[i][1]);
			close(value->pipefds[i][0]);
			value->argu = funct_split(argv[j], ' ');
			value->path = ft_find_path(env, value->argu[0], value);
			execve(value->path, value->argu[i], env);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	value->pid = fork();
	if (value->pid  < 0)
		return (3);
	if (value->pid == 0)
	{
		dup2(value->pipefds[i][0], STDIN_FILENO);
		close(value->pipefds[i][0]);
		close(value->pipefds[i][1]);
		value->argu2 = funct_split(argv[i], ' ');
		value->path = ft_find_path(env, value->argu2[0], value);
		execve(value->path, value->argu2, env);
		exit(EXIT_SUCCESS);
	}
	close(value->pipefds[i][0]);
	close(value->pipefds[i][1]);
    waitpid(-1, NULL, 0);
    return (EXIT_SUCCESS);
}
