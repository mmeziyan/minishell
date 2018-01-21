/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:47:44 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/12/25 19:47:46 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	buil_pwd(t_data *d)
{
	char	cwd[1024];
	t_env	*tmp;

	if (ft_strcmp(d->argv[0], "pwd\0") != 0)
		return (0);
	if ((getcwd(cwd, sizeof(cwd))))
		ft_putendl(cwd);
	else
		ft_putendl_fd("pwd: .: No such file or directory\n", 2);
	return (1);
}

int	buil_clear(t_data *d)
{
	if (ft_strcmp(d->argv[0], "clear\0") != 0)
		return (0);
	ft_putstr("\033[2J\033[0;0H");
	return (1);
}
