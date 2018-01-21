/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:48:11 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/12/25 19:48:12 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		last_occurence(char *str, char c)
{
	int		i;
	int		n;
	char	*ptr;

	n = -1;
	i = -1;
	ptr = NULL;
	while (str[++i])
		if (str[i] == c)
			n = i;
	return (n);
}

char	**ft_tabcpy(char **tab)
{
	int		n;
	char	**new;

	n = ft_tabtool(tab, "len");
	if (!(new = malloc(sizeof(char *) * (n + 1))))
		exit(-1);
	n = -1;
	while (tab[++n])
		new[n] = ft_strdup(tab[n]);
	new[n] = NULL;
	return (new);
}

void	free_data(t_data *d)
{
	if (d->path)
		free_tab(&d->path);
	if (d->argv)
		free_tab(&d->argv);
	if (d->myenv)
		free_tab(&d->myenv);
	if (d->argvs)
		free_tab(&d->argvs);
	ft_switch(0);
}

void	ft_putcolor(int nb, ...)
{
	va_list	ap;
	char	color;

	ft_putstr("\x1B[0m");
	if (nb > 0)
		va_start(ap, nb);
	while (nb-- > 0 && (color = va_arg(ap, int)))
	{
		color == 'r' ? ft_putstr("\x1B[31m") : 0;
		color == 'v' ? ft_putstr("\x1B[32m") : 0;
		color == 'y' ? ft_putstr("\x1B[33m") : 0;
		color == 'b' ? ft_putstr("\x1B[34m") : 0;
		color == 'p' ? ft_putstr("\x1B[35m") : 0;
		color == 'c' ? ft_putstr("\x1B[36m") : 0;
		color == 'g' ? ft_putstr("\x1B[37m") : 0;
		color == 'G' ? ft_putstr("\x1B[1m") : 0;
		color == 'B' ? ft_putstr("\x1B[3m") : 0;
		color == 'U' ? ft_putstr("\x1B[4m") : 0;
	}
}

void	free_tab(char ***tab)
{
	int	n;

	n = -1;
	while ((*tab)[++n])
	{
		free((*tab)[n]);
		(*tab)[n] = NULL;
	}
	free(*tab);
	*tab = NULL;
}
