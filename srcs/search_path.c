/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 17:00:00 by hdrumus           #+#    #+#             */
/*   Updated: 2017/07/01 12:33:20 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hyper_header.h"

char	*extract_path(char **env, char *field, int offset)
{
	int		i;
	char	*good_row;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(field, env[i], offset) == 0)
		{
			good_row = ft_strdup(env[i]);
			return (good_row);
		}
	}
	return (NULL);
}

char	*search_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	*cmd_path;
	char	**splitted_path;
	DIR		*p_dir;

	p_dir = NULL;
	path = extract_path(env, "PATH=", 5);
	if (!path)
		return (NULL);
	splitted_path = ft_strsplit(path + 5, ':');
	i = -1;
	if ((cmd_path = good_path(splitted_path, p_dir, cmd)))
		return (cmd_path);
	return (NULL);
}

char	*good_path(char **splitted_path, DIR *p_dir, char *cmd)
{
	int				i;
	char			*cmd_path;
	struct dirent	*p_dirent;

	i = -1;
	while (splitted_path[++i])
	{
		p_dir = opendir(splitted_path[i]);
		while ((p_dirent = readdir(p_dir)) != NULL)
		{
			if (ft_strcmp(p_dirent->d_name, cmd) == 0)
			{
				cmd_path = ft_strjoin(ft_strjoin(splitted_path[i], "/"), cmd);
				if (access(cmd_path, X_OK) == 0)
					return (cmd_path);
				else
					return (NULL);
			}
		}
	}
	return (NULL);
}
