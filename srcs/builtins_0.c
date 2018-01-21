/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:47:37 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/12/25 19:47:39 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		buil_echo(t_data *d)
{
	int	n;

	n = 0;
	if (ft_strcmp(d->argv[0], "echo\0") != 0)
		return (0);
	if (!d->argv[1])
		ft_putendl("");
	while (d->argv[++n])
	{
		ft_putstr(d->argv[n]);
		d->argv[n + 1] ? ft_putchar(' ') : ft_putchar('\n');
	}
	return (1);
}

int		buil_exit(t_data *d)
{
	char	*ptr;

	ptr = NULL;
	if (ft_strcmp(d->argv[0], "exit\0") != 0)
		return (0);
	if (d->argv[1] && d->argv[2])
	{
		my_printf("exit: too many arguments\n", 2);
		return (1);
	}
	my_printf("exit\n", 1);
	if (d->argv[1])
	{
		if ((ptr = ft_just_num(d->argv[1])))
		{
			my_printf("exit: '%s': numeric argument required\n", 2, ptr);
			exit(-1);
		}
		exit(ft_atoi(d->argv[1]));
	}
	if (!d->argv[1])
		exit(0);
	return (1);
}

int		buil_unset(t_data *d)
{
	int	n;

	n = 0;
	if (ft_strcmp(d->argv[0], "unsetenv\0") != 0)
		return (0);
	while (d->argv[++n])
	{
		if (ft_strchr(d->argv[n], '='))
		{
			my_printf("unsetenv: %s: not a valid identifier\n", 2, d->argv[n]);
			continue ;
		}
		env_del(d, d->argv[n]);
	}
	return (1);
}

int		buil_setenv(t_data *d)
{
	if (ft_strcmp(d->argv[0], "setenv\0") != 0)
		return (0);
	if (!d->argv[1])
		aff_env(d);
	if (d->argv[1] && d->argv[2] && d->argv[3])
		my_printf("setenv: too many arguments\n", 2);
	if (d->argv[1] && d->argv[2] && !d->argv[3])
	{
		if (d->argv[1][0] == '_' && d->argv[1][1] == '\0')
			return (1);
		if (ft_strchr(d->argv[1], '=') || !ft_isalpha(d->argv[1][0]))
		{
			my_printf("setenv: '%s': not a valid identifier\n", 2, d->argv[1]);
			return (1);
		}
		add_env(d, d->argv[1], d->argv[2]);
	}
	return (1);
}

int		builtins(t_data *d)
{
	int	n;

	n = 0;
	n = buil_exit(d) ? 1 : n;
	n = buil_echo(d) ? 1 : n;
	n = buil_env(d) ? 1 : n;
	n = buil_unset(d) ? 1 : n;
	n = buil_setenv(d) ? 1 : n;
	n = buil_cd(d) ? 1 : n;
	n = buil_pwd(d) ? 1 : n;
	n = buil_clear(d) ? 1 : n;
	return (n);
}
