/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:31:13 by hdrumus           #+#    #+#             */
/*   Updated: 2017/06/30 20:20:17 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hyper_header.h"

char		*ft_trim(char const *s)
{
	char const *e;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == 39 || *s == '"')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	e = s + ft_strlen(s) - 1;
	while (*e == ' ' || *e == '\t' || *e == '\n' || *e == 39 || *e == '"')
		e--;
	return (ft_strsub(s, 0, e - s + 1));
}

static int	try_hard(char **envp, char *key)
{
	int i;
	int c;

	c = 1;
	i = 0;
	while (envp[i] && c)
	{
		if (ft_strncmp(key, envp[i], ft_strlen(key)) == 0)
			c = 0;
		else
			i++;
	}
	return (i);
}

void		set_env(char ***en, char *s)
{
	char	*key;
	int		i;
	char	**envp;

	envp = *en;
	if (!s || !ft_strchr(s, '='))
		ft_printf(COLOR_GREEN "how about: setenv [key=value]\n" C_RES);
	else
	{
		key = ft_strcdup(s, '=');
		i = try_hard(envp, ft_strjoin(key, "="));
		if (envp[i])
			envp[i] = ft_strdup(ft_trim(s));
		else
		{
			envp[i] = ft_strdup(ft_trim(s));
			envp[i + 1] = 0;
		}
	}
	*en = envp;
}
