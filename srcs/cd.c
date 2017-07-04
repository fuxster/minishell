/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:41:24 by hdrumus           #+#    #+#             */
/*   Updated: 2017/07/03 12:21:56 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hyper_header.h"

int		valid_dir(char *av)
{
	DIR *p_dir;

	p_dir = NULL;
	if (access(av, F_OK) == 0)
	{
		if (access(av, R_OK) == 0)
		{
			p_dir = opendir(av);
			if (p_dir != NULL)
				if (chdir(av) == 0)
				{
					closedir(p_dir);
					return (1);
				}
		}
		else
			ft_printf("[cd]: %s: Permission denied\n", av);
	}
	else
	{
		ft_printf(C_RED BOLD "[cd]: " C_RES);
		ft_printf("%s:  No such file or directory\n", av);
	}
	return (0);
}

void	set_pwd(char *path, char ***env)
{
	int		i;
	char	**temp_env;
	char	*old_pwd;

	i = -1;
	temp_env = *env;
	while (temp_env[++i])
	{
		if (ft_strncmp(temp_env[i], "PWD=", 4) == 0)
		{
			old_pwd = ft_strchr(temp_env[i], '=') + 1;
			temp_env[i] = ft_strjoin("PWD=", path);
		}
	}
	i = -1;
	while (temp_env[++i])
		if (ft_strncmp(temp_env[i], "OLDPWD=", 7) == 0)
			temp_env[i] = ft_strjoin("OLDPWD=", old_pwd);
	*env = temp_env;
}

int		cd(int ac, char **av, char ***env)
{
	char	**temp_env;
	char	*temp_path;
	char	*r_path;

	(void)ac;
	temp_path = NULL;
	temp_env = *env;
	r_path = (char *)malloc(sizeof(char) * MAX_PATH);
	bzero(r_path, MAX_PATH);
	power_gers(av, &temp_env, temp_path, r_path);
	*env = temp_env;
	free(r_path);
	return (1);
}

void	power_gers(char **av, char ***env, char *t_path, char *r_path)
{
	int		i;
	char	**temp_env;

	i = -1;
	temp_env = *env;
	if (!av[1] || (ft_strcmp(av[1], "~") == 0))
		cd_hometilda(&temp_env, r_path, t_path, i) ? *env = temp_env : 0;
	else if (ft_strncmp(av[1], "~/", 2) == 0)
		cd_absolute_tilda(&temp_env, av, r_path, t_path) ? *env = temp_env : 0;
	else if (ft_strcmp(av[1], "-") == 0)
		cd_minus(&temp_env) ? *env = temp_env : 0;
	else if (av[1][0] == '/')
		cd_absolute(av, &temp_env) ? *env = temp_env : 0;
	else if (ft_strcmp(av[1], "..") == 0)
		cd_double_dot(&temp_env, r_path, t_path) ? *env = temp_env : 0;
	else
		cd_relative(&temp_env, r_path, av) ? *env = temp_env : 0;
}
