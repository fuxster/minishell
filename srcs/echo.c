/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 14:43:36 by hdrumus           #+#    #+#             */
/*   Updated: 2017/07/03 12:13:29 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hyper_header.h"

int		print_env(char **env, char *str, int i)
{
	int		len;
	int		j;
	char	*env_field;
	char	*env_extract;

	j = i;
	while (!ft_iswhite(str[j]) && str[j] && str[j] != 39 && str[j] != '"')
		j++;
	len = j - i - 1;
	env_field = (char *)malloc(sizeof(char) * len + 1);
	env_field = ft_strncpy(env_field, str + i + 1, len);
	env_extract = extract_path(env, env_field, ft_strlen(env_field));
	if (env_extract != NULL)
	{
		ft_putstr(env_extract + len + 1);
		free(env_field);
		return (j);
	}
	free(env_field);
	return (j);
}

int		while_white(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	ft_putchar(' ');
	return (i);
}

void	ft_echo(char *str, char **env)
{
	int				i;
	t_state			*status;

	status = (t_state *)malloc(sizeof(t_state));
	i = 5;
	status->hard = 0;
	status->soft = 0;
	while (str[i])
		ft_echo_help(str, &i, env, status);
	ft_putchar('\n');
}

void	ft_echo_help(char *str, int *i, char **env, t_state *status)
{
	if (str[*i] == 39 && status->hard == 1)
		status->hard = 0;
	else if (str[*i] == '"' && status->soft == 1)
		status->soft = 0;
	else if (str[*i] == 39 && status->soft == 1 && str[*i] != '$')
		ft_putchar(str[*i]);
	else if (str[*i] == '"' && status->hard == 1 && str[*i] != '$')
		ft_putchar(str[*i]);
	else if (str[*i] == 39 && status->soft == 0)
		status->hard = 1;
	else if (str[*i] == '"' && status->hard == 0)
		status->soft = 1;
	else if (ft_iswhite((int)str[*i]) && !status->hard && !status->soft)
		*i = while_white(str, *i) - 1;
	else if (ft_iswhite((int)str[*i]) && (status->hard || status->soft))
		ft_putchar(str[*i]);
	else if (str[*i] == '$')
		*i = print_env(env, str, *i) - 1;
	else
		ft_putchar(str[*i]);
	(void)(*i)++;
}
