/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:58:41 by tpicoule          #+#    #+#             */
/*   Updated: 2023/01/31 13:32:25 by tpicoule         ###   ########.fr       */
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
	int		pipefd[2];
	char	**goodpath;
	char	**argu2;
	char	**argu;
	char	*path;
	char	*newenv;
	int		pid;

}	t_pipex;

char	*ft_strjoin(char const *s1, char const *s2);
size_t	funct_counti(char const *s, char c);
char	**funct_countj(char **tabtab, char *s, char c);
char	**funct_split(char *s, char c);
char	*ft_substr(char *s, int start, int end);
char	*ft_find_path(char **env, char *cmd, t_pipex *value);
size_t	ft_strlen(const char *str);
char	*ft_strjoinfree(char *stock, char *tmp);

#endif