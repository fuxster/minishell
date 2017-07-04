/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:26:49 by hdrumus           #+#    #+#             */
/*   Updated: 2017/01/11 16:26:50 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char *aux;

	aux = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (aux == NULL)
		return (NULL);
	else
		return (ft_strcpy(aux, s));
}
