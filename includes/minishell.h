/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 20:06:08 by mmeziyan          #+#    #+#             */
/*   Updated: 2017/12/25 20:06:09 by mmeziyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <curses.h>
# include <termios.h>

typedef void(*t_sighandler)(int);
typedef struct stat	t_stat;

typedef struct		s_env
{
	struct s_env	*prev;
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_data
{
	t_env	*begin;
	t_env	*end;
	int		len;
	char	**myenv;

	char	*last;
	char	**path;
	char	**argv;
	char	**argvs;
}					t_data;

void				minishell(t_data *d);

t_sighandler		signal(int signum, t_sighandler handler);
void				control_c(int param);
void				ft_switch(int n);

void				list_ini(t_data *data);
void				list_clean(t_data *data);
void				mcreate(t_env **new);
void				mdestroy(t_data *d, t_env *destroy);
void				mfree(t_env **destroy);
void				add_right(t_data *data, t_env *new);

int					prompt(t_data *d);
void				add_env(t_data *d, char *name, char *value);
t_env				*env_search(t_data *d, char *name);
void				first_env(t_data *d, char **av);
void				aff_env(t_data *d);
void				env_del(t_data *d, char *name);
void				recupath(t_data *d);
void				get_env(t_data *d, char **tab);

int					builtins(t_data *d);
int					buil_cd(t_data *d);
int					buil_echo(t_data *d);
int					buil_exit(t_data *d);
int					buil_unset(t_data *d);
int					buil_env(t_data *d);
int					buil_setenv(t_data *d);
int					buil_pwd(t_data *d);
int					buil_clear(t_data *d);

int					execute(t_data *d);
void				commands(t_data *d);

void				list_to_tab(t_data *d);
int					last_occurence(char *str, char c);
void				free_data(t_data *d);
char				**ft_tabcpy(char **tab);
void				ft_putcolor(int nb, ...);
void				free_tab(char ***tab);

#endif
