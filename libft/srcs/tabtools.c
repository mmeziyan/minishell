/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabtools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 19:53:52 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/09/24 19:53:55 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabtool(char **tab, char *task)
{
	int i;

	i = -1;
	if (ft_strcmp(task, "len") == 0)
	{
		while (tab[++i])
			;
		return (i);
	}
	if (ft_strcmp(task, "del") == 0)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
		return (0);
	}
	if (ft_strcmp(task, "put") == 0)
		while (tab[++i])
			ft_putendl(tab[i]);
	return (i);
}

void	ft_tab_rev(char ***tab, int begin)
{
	char	*tmp;
	int		a;
	int		z;

	a = begin;
	z = ft_tabtool(*tab, "len") - 1;
	while (a < z)
	{
		tmp = (*tab)[a];
		(*tab)[a] = (*tab)[z];
		(*tab)[z] = tmp;
		a++;
		z--;
	}
}

void	ft_tab_sort(char **tab, int begin)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	i = begin - 1;
	j = i;
	len = ft_tabtool(tab, "len");
	while (++i < len)
	{
		while (++j < len)
			if (ft_strcmp(tab[i], tab[j]) < 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		j = begin - 1;
	}
}

void	ft_tab_sort2(char **tab, long int *tab2, int begin)
{
	char		*tmp;
	long int	tmp2;
	int			i;
	int			j;
	int			len;

	i = begin - 1;
	j = i;
	len = ft_tabtool(tab, "len");
	while (++i < len)
	{
		while (++j < len)
			if (tab2[i] > tab2[j])
			{
				tmp = tab[i];
				tmp2 = tab2[i];
				tab[i] = tab[j];
				tab2[i] = tab2[j];
				tab[j] = tmp;
				tab2[j] = tmp2;
			}
		j = begin - 1;
	}
}
