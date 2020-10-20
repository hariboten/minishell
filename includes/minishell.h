/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:28:47 by ewatanab          #+#    #+#             */
/*   Updated: 2020/10/20 16:06:03 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"

# define STR_OPT_LN "-n"
# define EM_TOO_MANY_ARG "too many arg"
# define MINISHELL "minishell :"
# define PATH_MAX 1023

typedef enum	e_errno
{
	TOO_MANY_ARG,
	FEW_ARG
}	t_errno;

typedef struct	s_commands
{
	t_list	*com;
	t_list	*args;
	t_list	*input;
	t_list	*output;
}	t_commands;

typedef	struct	s_exec
{
	t_list	*list;
	char	**argv;
	char	**envp;
	int		fd_in;
	int		fd_out;
}				t_exec;

void	minishell();
int		sh_exit();
int		sh_echo(char **argv);
int		sh_cd(char **argv);
int		sh_env(char **argv);
int		sh_export(char **argv);
int		sh_unset(char **argv);

#endif
