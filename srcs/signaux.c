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

int		g_switch;

void	control_c(int param)
{
	param = 127;
	if (g_switch)
	{
		ft_putendl("");
		return ;
	}
	ft_putcolor(2, 'r', 'G');
	ft_putstr("\nTerminator");
	ft_putcolor(2, 'b', 'G');
	ft_putstr("->");
	ft_putcolor(0);
}

void	ft_switch(int n)
{
	g_switch = n ? 1 : 0;
}
