/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:48:02 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/12/25 19:48:03 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_ini(t_data *data)
{
	data->begin = NULL;
	data->end = NULL;
	data->last = NULL;
	data->path = NULL;
	data->argv = NULL;
	data->myenv = NULL;
	data->len = 0;
}

void	mcreate(t_env **new)
{
	(*new = (t_env *)malloc(sizeof(t_env))) ? *new : exit(-1);
	(*new)->prev = NULL;
	(*new)->next = NULL;
}

void	mdestroy(t_data *d, t_env *destroy)
{
	if (destroy->next && destroy->prev)
	{
		destroy->next->prev = destroy->prev;
		destroy->prev->next = destroy->next;
	}
	if (destroy->next && !destroy->prev)
	{
		destroy->next->prev = NULL;
		d->begin = destroy->next;
	}
	if (!destroy->next && destroy->prev)
	{
		destroy->prev->next = NULL;
		d->end = destroy->prev;
	}
	if (!destroy->next && !destroy->prev)
	{
		d->begin = NULL;
		d->end = NULL;
	}
	mfree(&destroy);
}

void	mfree(t_env **destroy)
{
	free((*destroy)->name);
	(*destroy)->name = NULL;
	if ((*destroy)->value)
	{
		free((*destroy)->value);
		(*destroy)->value = NULL;
	}
	free(*destroy);
}

void	add_right(t_data *data, t_env *new)
{
	data->len++;
	if (!data->begin)
	{
		data->end = new;
		data->begin = new;
	}
	else
	{
		data->end->next = new;
		new->prev = data->end;
		data->end = new;
		new->next = NULL;
	}
}
