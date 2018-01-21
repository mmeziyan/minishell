/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:47:57 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/12/25 19:47:58 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_del(t_data *d, char *name)
{
	t_env	*tmp;

	if ((tmp = env_search(d, name)))
		mdestroy(d, tmp);
}

void	aff_env(t_data *d)
{
	t_env	*tmp;

	tmp = d->begin;
	while (tmp)
	{
		my_printf("%s=%s\n", 1, tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

void	add_env(t_data *d, char *name, char *value)
{
	t_env	*tmp;

	tmp = env_search(d, name);
	if (tmp)
	{
		if (tmp->value)
			ft_strdel(&tmp->value);
		if (value)
			tmp->value = ft_strdup(value);
	}
	if (!tmp)
	{
		mcreate(&tmp);
		tmp->name = ft_strdup(name);
		tmp->value = (value) ? ft_strdup(value) : NULL;
		add_right(d, tmp);
	}
}

t_env	*env_search(t_data *d, char *name)
{
	t_env	*tmp;

	tmp = d->begin;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	get_env(t_data *d, char **tab)
{
	int		n;
	char	*ptr;
	t_env	*new;

	list_ini(d);
	n = -1;
	while (tab[++n])
	{
		if (!(ptr = ft_strchr(tab[n], '=')))
			exit(-1);
		mcreate(&new);
		new->name = ft_strndup(tab[n], ptr - &tab[n][0]);
		new->value = *(ptr + 1) ? ft_strdup(ptr + 1) : NULL;
		add_right(d, new);
	}
}
