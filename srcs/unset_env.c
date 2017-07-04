/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:03:21 by hdrumus           #+#    #+#             */
/*   Updated: 2017/06/29 17:48:14 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hyper_header.h"

void	unset_env(char ***s, char *key)
{
	char	**env;
	int		i;

	i = 0;
	env = *s;
	while (env[i] && ft_strncmp(key, env[i], ft_strlen(key)))
		i++;
	if (env[i])
	{
		while (env[i + 1])
		{
			env[i] = env[i + 1];
			i++;
		}
		env[i] = 0;
	}
	*s = env;
}
