/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:58:41 by tpicoule          #+#    #+#             */
/*   Updated: 2023/02/06 09:47:10 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	int		file1;
	int		file2;
	int		cmds;
	int		pid;
	int		**pipefds;
	int		nbpipes;
	//int		pid[cmds];
	char	**argu;
	char	**argu2;
	char	*path;
	char	*newenv;
	char	**goodpath;

}	t_pipex;

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_counti(char *s, char c);
char	**ft_countj(char **tabtab, char *s, char c);
char	**funct_split(char *s, char c);
char	*ft_substr(char *s, int start, int end);
char	*ft_find_path(char **env, char *cmd, t_pipex *value);
size_t	ft_strlen(char *str);
char	*ft_strjoinfree(char *stock, char *tmp);

#endif