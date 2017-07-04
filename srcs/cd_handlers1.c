/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_handlers1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 14:34:42 by hdrumus           #+#    #+#             */
/*   Updated: 2017/07/03 12:13:51 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hyper_header.h"

int		cd_hometilda(char ***env, char *r_path, char *temp_path, int i)
{
	char **temp_env;

	temp_env = *env;
	while (temp_env[++i])
	{
		if (ft_strncmp(temp_env[i], "HOME=", 5) == 0)
		{
			temp_path = ft_strdup(ft_strchr(temp_env[i], '=') + 1);
			r_path = ft_strjoin(temp_path, "/");
			break ;
		}
	}
	if (*r_path == '\0')
	{
		ft_printf(BOLD C_RED "HOME isn`t set" C_RES);
		return (0);
	}
	else if (valid_dir(r_path))
	{
		set_pwd(r_path, &temp_env);
		*env = temp_env;
	}
	return (1);
}

int		cd_absolute_tilda(char ***env, char **av, char *r_p, char *t_p)
{
	char **temp_env;

	temp_env = *env;
	t_p = extract_path(temp_env, "HOME=", 5);
	if (t_p == NULL)
	{
		ft_printf(BOLD C_RED "cd: HOME isn`t set" C_RES);
		return (0);
	}
	r_p = ft_strjoin(t_p + 5, ft_strjoin("/", (ft_strchr(av[1], '/') + 1)));
	if (valid_dir(r_p))
	{
		set_pwd(r_p, &temp_env);
		*env = temp_env;
	}
	return (1);
}

int		cd_minus(char ***env)
{
	char **temp_env;
	char *temp_path;

	temp_env = *env;
	temp_path = extract_path(temp_env, "OLDPWD=", 7);
	if (temp_path == NULL)
	{
		ft_printf(C_RED BOLD "OLDPWD not set" C_RES);
		return (0);
	}
	if (valid_dir(temp_path + 7))
	{
		set_pwd(temp_path + 7, &temp_env);
		*env = temp_env;
	}
	return (1);
}

int		cd_absolute(char **av, char ***env)
{
	char **temp_env;

	temp_env = *env;
	if (valid_dir(av[1]))
	{
		set_pwd(av[1], &temp_env);
		*env = temp_env;
	}
	else
		return (0);
	return (1);
}

int		cd_double_dot(char ***env, char *r_path, char *t_path)
{
	char **temp_env;

	temp_env = *env;
	r_path = getcwd(r_path, MAX_PATH);
	t_path = ft_strrchr(r_path, '/');
	if (valid_dir(ft_strjoin(r_path, "/..")))
	{
		if (ft_strlen(r_path) - ft_strlen(t_path) != 0)
			r_path[ft_strlen(r_path) - ft_strlen(t_path)] = '\0';
		set_pwd(r_path, &temp_env);
		*env = temp_env;
		return (1);
	}
	return (0);
}
