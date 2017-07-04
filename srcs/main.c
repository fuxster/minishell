/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 17:00:07 by hdrumus           #+#    #+#             */
/*   Updated: 2017/07/01 12:33:19 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hyper_header.h"

int		fork_builtin(int ac, char **args, char ***env, char *notr_ar)
{
	char **temp_env;

	temp_env = *env;
	if (ft_strncmp(args[0], "cd", 2) == 0)
	{
		cd(ac, args, &temp_env);
		*env = temp_env;
	}
	else if (ft_strncmp(args[0], "env", 3) == 0)
		ft_env(temp_env);
	else if (ft_strncmp(args[0], "echo", 4) == 0)
		ft_echo(notr_ar, temp_env);
	else if (ft_strncmp(args[0], "exit", 4) == 0)
	{
		ft_printf(C_YE "[exit]\n" C_RES);
		exit(1);
	}
	else if (ft_strncmp(args[0], "setenv", 6) == 0)
		set_env(&temp_env, args[1]);
	else if (ft_strncmp(args[0], "unsetenv", 8) == 0)
		unset_env(&temp_env, args[1]);
	return (1);
}

int		fork_real_builtin(char *path, char **args, char **env)
{
	uid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, env) == -1)
		{
			ft_printf(C_RED BOLD "[%s]: " C_RES, args[0]);
			ft_printf(C_YE "command not found\n" C_RES);
		}
		exit(1);
	}
	wait(NULL);
	return (1);
}

void	analyze1(char **args, char **env)
{
	char *b_p;

	if ((b_p = search_path(args[0], env)) != NULL)
		fork_real_builtin(b_p, args, env);
	else if (args[0][0] == '/')
		fork_real_builtin(args[0], args, env);
	else
	{
		ft_printf(C_RED BOLD "[%s]: " C_RES, args[0]);
		ft_printf(C_YE "command not found\n" C_RES);	
	}
}

void	analyze(char *buff, char ***env)
{
	int		i;
	int		ac;
	char	**temp_env;
	char	**args;
	char	**builtins;

	ac = 0;
	temp_env = *env;
	builtins = (ft_strsplit("echo cd setenv unsetenv echo exit", ' '));
	args = ft_strsplit(buff, ' ');
	while (args[ac++])
		args[ac] = ft_strtrim(args[ac]);
	i = -1;
	while (builtins[++i])
	{
		if (ft_strcmp(builtins[i], args[0]) == 0)
		{
			fork_builtin(ac, args, &temp_env, buff);
			*env = temp_env;
			return ;
		}
	}
	analyze1(args, temp_env);
}

int		main(int ac, char **av, char **env)
{
	char *buff;

	(void)ac;
	(void)av;
	while (1)
	{
		ft_putstr(COLOR_BLUE BOLD "Shila-≥ " C_RES);
		get_next_line(0, &buff);
		buff = ft_strtrim(buff);
		if (*buff != 0)
			analyze(buff, &env);
	}
	return (0);
}
