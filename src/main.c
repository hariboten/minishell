/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:29:16 by ewatanab          #+#    #+#             */
/*   Updated: 2020/09/11 12:52:12 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		minishell();
	else
	{
		ft_putstr_fd(MINISHELL, 2);
		ft_putstr_fd(EM_TOO_MANY_ARG, 2);
	}
	return (0);
}
