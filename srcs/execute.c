/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:47:57 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/12/25 19:47:58 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		right(t_data *d, const char *path)
{
	t_stat	sta;

	lstat(path, &sta);
	if (sta.st_mode & S_IXUSR)
		return (1);
	return (0);
}

int		execute(t_data *d)
{
	int		n;
	char	*prog;

	prog = NULL;
	n = -1;
	if ((ft_strncmp(d->argv[0], "./", 2) || d->argv[0][0] == '/') && \
		access(*d->argv, X_OK) == 0)
		execve(d->argv[0], d->argv, d->myenv);
	while (d->path && d->path[++n])
	{
		prog = ft_strjoins(3, d->path[n], "/", d->argv[0]);
		if (access(prog, X_OK) == 0)
			execve((const char *)prog, d->argv, d->myenv);
		if (access(prog, F_OK) == 0 && !right(d, prog))
		{
			my_printf("permission denied: %s\n", 2, d->argv[0]);
			exit(-1);
		}
		ft_strdel(&prog);
	}
	if (access(d->argv[0], F_OK) == 0 && !right(d, d->argv[0]))
		my_printf("permission denied: %s\n", 2, d->argv[0]);
	else
		my_printf("command not found: %s\n", 2, d->argv[0]);
	exit(-1);
}

void	commands(t_data *d)
{
	pid_t	son;
	char	**tab;
	int		n;

	n = 0;
	ft_switch(1);
	if (builtins(d))
	{
		free_tab(&d->argv);
		d->argv = ft_white_space(d->argvs[n + 1]);
		n++;
	}
	if ((son = fork()) == -1)
		exit(-1);
	if (son > 0)
		wait(NULL);
	if (son == 0)
		execute(d);
}
