/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:59:38 by tpicoule          #+#    #+#             */
/*   Updated: 2023/02/06 16:35:06 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
//#include <signal.h>

int	main(int argc, char **argv, char **env)
{
	t_pipex	*value;
	int		file1;
	int		file2;
	int		i;
	int		j;

	i = 0;
	value = malloc(sizeof(*value));
	if (!value)
		return (0);
	value->cmds = argc - 3;
	value->nbpipes = value->cmds - 1;
	j = 2;
	value->pipefds = malloc(sizeof(int *) * value->cmds);
		if (!value->pipefds)
			return (0);
	
		if (argc < 4)
	{
		perror("ERROR too few args");
		exit(EXIT_FAILURE);
	}

	//ON GERE LES OPEN ET LES FILES
	file1 = open(argv[1], O_RDONLY, 0777);
	file2 = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup2(file1, STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);

	//ON CREER LES PIPES
	j = 3;
	while (value->nbpipes > 0)
	{
		value->pipefds[i] = malloc(sizeof(int) * 2);
		pipe(value->pipefds[i]);
		if (pipe(value->pipefds[i]) == -1)
			return (1);
		i++;
		value->nbpipes--;
	}
	i = 0;	
	//ON CREER LES ENFANTS(INCHALLAH ON LES TUES)
    
    value->pid = fork();
    if (value->pid < 0)
        return (3);
    if (value->pid == 0)
    {
        dup2(value->pipefds[i][1], STDOUT_FILENO);
        close(value->pipefds[i][1]);
        close(value->pipefds[i][0]);
        value->argu = funct_split(argv[2], ' ');
        value->path = ft_find_path(env, value->argu[0], value);
        execve(value->path, value->argu, env);
        exit(EXIT_SUCCESS);
    }
    
	while (i != value->cmds - 2)
	{
		value->pid = fork();
		if (value->pid < 0)
			return (2);
		if (value->pid == 0)
		{
			printf("%d/n", i);
			dup2(value->pipefds[i][1], STDOUT_FILENO);
			close(value->pipefds[i][1]);
			close(value->pipefds[i][0]);
			value->argu = funct_split(argv[j], ' ');
			value->path = ft_find_path(env, value->argu[0], value);
			execve(value->path, value->argu, env);
			exit(EXIT_SUCCESS);
		}
		i++;
		j++;
	}
	value->pid = fork();
	if (value->pid  < 0)
		return (3);
	if (value->pid == 0)
	{
		dup2(value->pipefds[i][0], STDIN_FILENO);
		close(value->pipefds[i][0]);
		close(value->pipefds[i][1]);
		value->argu2 = funct_split(argv[j], ' ');
		value->path = ft_find_path(env, value->argu2[0], value);
		execve(value->path, value->argu2, env);
		exit(EXIT_SUCCESS);
	}
	close(value->pipefds[i][0]);
	close(value->pipefds[i][1]);
    waitpid(-1, NULL, 0);
    return (EXIT_SUCCESS);
}
