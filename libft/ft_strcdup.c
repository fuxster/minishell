/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:38:14 by hdrumus           #+#    #+#             */
/*   Updated: 2017/06/29 17:38:15 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(char *s, char n)
{
	char	*d;
	int		i;

	i = 0;
	if (!(d = (char *)malloc(ft_poschr(s, n) + 1)))
		return (NULL);
	ft_strccpy(d, s, n);
	return (d);
}
