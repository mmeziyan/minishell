/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:47:44 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/12/25 19:47:46 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				buil_env(t_data *d)
{
	if (ft_strcmp(d->argv[0], "env\0") != 0)
		return (0);
	aff_env(d);
	return (1);
}

static void		translate_1(char **tab, char **new)
{
	char	*tmp;
	int		pos;
	int		n;

	n = -1;
	while (tab[++n])
	{
		if (ft_strcmp(tab[n], "..\0") == 0)
		{
			tmp = *new;
			pos = last_occurence(tmp, '/');
			*new = (pos == 0) ? ft_strdup("/") : ft_strndup(*new, pos);
			ft_strdel(&tmp);
		}
		else if (ft_strcmp(tab[n], ".\0") == 0)
			continue ;
		else
		{
			tmp = *new;
			*new = (new[0][1]) ? ft_strjoins(3, *new, "/", tab[n]) :
				ft_strjoin(*new, tab[n]);
			ft_strdel(&tmp);
		}
	}
}

static char		*translate(char *str)
{
	char	*new;
	char	**tab;
	char	cwd[1024];

	if (str[0] != '/' && getcwd(cwd, sizeof(cwd)))
		new = ft_strdup(cwd);
	else
		new = ft_strdup("/");
	tab = ft_strsplit(str, '/');
	translate_1(tab, &new);
	free_tab(&tab);
	return (new);
}

static int		move_to(t_data *d, char *dest)
{
	char	cwd[1024];
	char	*clean;

	getcwd(cwd, sizeof(cwd));
	clean = translate(dest);
	if (chdir(clean) == 0)
	{
		if (cwd[0])
			add_env(d, "OLDPWD", cwd);
		add_env(d, "PWD", clean);
	}
	else
	{
		my_printf("cd: '%s': ", 2, dest);
		if (access(dest, F_OK) == -1)
			ft_putstr_fd("no such file or directory\n", 2);
		else if (access(dest, R_OK) == -1)
			ft_putstr_fd("permission denied\n", 2);
		else
			ft_putstr_fd("not a directory\n", 2);
	}
	ft_strdel(&clean);
	return (1);
}

int				buil_cd(t_data *d)
{
	t_env	*tmp;

	if (ft_strcmp(d->argv[0], "cd\0") != 0)
		return (0);
	if (d->argv[1] && d->argv[2])
	{
		my_printf("cd: too many arguments\n", 2);
		return (1);
	}
	if (!(tmp = env_search(d, "HOME")) && !d->argv[1])
	{
		my_printf("cd: HOME not set\n", 2);
		return (1);
	}
	if (tmp && !d->argv[1])
		move_to(d, tmp->value);
	if (d->argv[1])
	{
		if (d->argv[1][0] == '-' && !d->argv[1][1])
			(tmp = env_search(d, "OLDPWD")) ? move_to(d, tmp->value) :
				my_printf("cd: OLDPWD not set\n", 2);
		else
			move_to(d, d->argv[1]);
	}
	return (1);
}
