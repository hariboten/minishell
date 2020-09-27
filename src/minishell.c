/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:47:17 by ewatanab          #+#    #+#             */
/*   Updated: 2020/09/24 17:11:43 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

sig_atomic_t	g_intflag;

void	sh_inthandler()
{
	ft_putstr("\nminishell > ");
	g_intflag = 1;
}

char	*ft_lstjoin(t_list *lst)
{
	char	*str;
	char	*tmp;

	if (!lst)
		return (ft_strdup(""));
	str = ft_strdup(lst->content);
	while (lst->next)
	{
		tmp = ft_strjoin(str, lst->next->content);
		free(str);
		str = tmp;
		lst = lst->next;
	}
	return (str);
}

char	*sh_prompt()
{
	char	*line;
	t_list	*store;
	int		ret;

	store = NULL;
	signal(SIGINT, sh_inthandler);
	ft_putstr("minishell > ");
	while ((ret = get_next_line(0, &line)) == 0)
	{
		if (g_intflag)
			ft_lstclear(&store, free);
		g_intflag = 0;
		if (!store && !ft_strcmp(line, ""))
		{
			free(line);
			ft_lstclear(&store, free);
			exit(0);
		}
		ft_lstadd_back(&store, ft_lstnew(line));
	}
	signal(SIGINT, SIG_DFL);
	if (g_intflag)
		ft_lstclear(&store, free);
	g_intflag = 0;
	//if (ret < 0)
		//sh_error();
	ft_lstadd_back(&store, ft_lstnew(line));
	line = ft_lstjoin(store);
	ft_lstclear(&store, free);
	return (line);
}

void	minishell()
{
	char	*line;

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
		if (!ft_strcmp(line, "exit"))
			exit(0);
		//sh_lounch(line);
	}
}
