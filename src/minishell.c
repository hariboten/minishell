/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:47:17 by ewatanab          #+#    #+#             */
/*   Updated: 2020/09/11 15:30:50 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

sig_atomic_t	g_intflag;

void	sh_inthandler()
{
	g_intflag = 1;
}

char	*sh_prompt()
{
	char	*line;
	char	*store;
	int		ret;

	store = NULL;
	ft_putstr("minishell > ");
	while ((ret = get_next_line(0, &line)) == 0)
	{
		store = ft_strjoin_tr(store, line);
		if (ft_strcmp(store, ""))
			return (store);
		if (g_intflag)
		{
			ft_free(store);
			return (ft_strdup(""));
		}
	}
	//if (ret < 0)
		//sh_error();
	return (ft_strjoin_tr(store, line));
}

void	minishell()
{
	char	*line;

	signal(SIGINT, sh_inthandler);
	while (1)
	{
		line = sh_prompt();
		if (g_intflag)
		{
			ft_free(line);
			g_intflag = 0;
			continue ;
		}
		ft_putstr(line);
		ft_putchar('\n');
		//sh_lounch(line);
	}
}
