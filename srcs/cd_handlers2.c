/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_handlers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:30:06 by hdrumus           #+#    #+#             */
/*   Updated: 2017/06/30 20:37:14 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hyper_header.h"

int		cd_relative(char ***env, char *r_path, char **av)
{
	char **temp_env;

	temp_env = *env;
	r_path = getcwd(r_path, MAX_PATH);
	if (ft_strcmp(av[1], ".") == 0)
		return (1);
	if (ft_strcmp(r_path, "/") != 0)
		r_path = ft_strjoin(ft_strjoin(r_path, "/"), av[1]);
	else
		r_path = ft_strjoin(r_path, av[1]);
	if (valid_dir(r_path))
	{
		set_pwd(r_path, &temp_env);
		*env = temp_env;
		return (1);
	}
	return (0);
}
