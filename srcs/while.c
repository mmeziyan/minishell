/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 20:06:08 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/12/25 20:06:09 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	first_env(t_data *d, char **av)
{
	char	cwd[1024];
	t_env	*tmp;
	char	*nbr;

	env_del(d, "_");
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		d->last = ft_strjoins(3, cwd, "/", av[0]);
	if (!(tmp = env_search(d, "PWD")))
		if (cwd[0])
			add_env(d, "PWD", cwd);
	if (!(tmp = env_search(d, "SHLVL")) ||
		(tmp && (!tmp->value || !ft_just_alpha(tmp->value))))
		add_env(d, "SHLVL", "1");
	else
	{
		nbr = ft_itoa(ft_atoi(tmp->value) + 1);
		add_env(d, "SHLVL", nbr);
		ft_strdel(&nbr);
	}
}

int		prompt(t_data *d)
{
	char	*command;

	ft_putcolor(2, 'r', 'G');
	ft_putstr("Terminator");
	ft_putcolor(2, 'v', 'G');
	ft_putstr("->");
	ft_putcolor(0);
	command = NULL;
	if (get_next_line(0, &command) != -1)
	{
		if (!command)
			exit(0);
		d->argvs = ft_strsplit(command, ';');
		if (d->argvs && d->argvs[0])
			d->argv = ft_white_space(d->argvs[0]);
		ft_strdel(&command);
		if (!d->argv || !d->argv[0])
			return (1);
		return (0);
	}
	return (1);
}

void	recupath(t_data *d)
{
	t_env	*tmp;

	d->path = NULL;
	if ((tmp = env_search(d, "PATH")))
		if (!(d->path = (ft_strsplit(tmp->value, ':'))))
			exit(-1);
}

void	list_to_tab(t_data *d)
{
	int		n;
	t_env	*tmp;

	n = -1;
	if (!(d->myenv = (char **)malloc(sizeof(char *) * (d->len + 1))))
		exit(-1);
	tmp = d->begin;
	while (tmp)
	{
		if (!(d->myenv[++n] = ft_strjoins(3, tmp->name, "=", tmp->value)))
			exit(-1);
		tmp = tmp->next;
	}
	d->myenv[++n] = NULL;
}
