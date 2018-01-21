/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:47:24 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/12/25 19:47:26 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_data *d)
{
	while (42)
	{
		ft_switch(0);
		free_data(d);
		if (prompt(d) || builtins(d))
			continue ;
		recupath(d);
		list_to_tab(d);
		commands(d);
	}
}

int		main(int ac, char **av, char **env)
{
	t_data d;

	ac++;
	get_env(&d, env);
	first_env(&d, av);
	signal(SIGINT, control_c);
	minishell(&d);
}
