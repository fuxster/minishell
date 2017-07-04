/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 11:51:59 by hdrumus           #+#    #+#             */
/*   Updated: 2017/06/28 17:24:30 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int		ft_rread(int const fd, char **stock)
{
	int		i;
	char	*str;
	char	*buffer;

	if (!(buffer = (char *)malloc(sizeof(*buffer) * (BUFF_SIZE + 1))))
		return (-1);
	i = read(fd, buffer, BUFF_SIZE);
	if (i > 0)
	{
		buffer[i] = '\0';
		str = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = str;
	}
	free(buffer);
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	static char	*s = NULL;
	char		*eol;
	int			i;

	if ((!s && (s = (char *)malloc(sizeof(*s))) == NULL) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	eol = ft_strchr(s, '\n');
	while (eol == NULL)
	{
		i = ft_rread(fd, &s);
		if (i == 0)
		{
			if (ft_strlen(s) == 0)
				return (0);
			s = ft_strjoin(s, "\n");
		}
		if (i < 0)
			return (-1);
		else
			eol = ft_strchr(s, '\n');
	}
	*line = ft_strsub(s, 0, ft_strlen(s) - ft_strlen(eol));
	s = ft_strdup(eol + 1);
	return (1);
}
