/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:31:04 by hdrumus           #+#    #+#             */
/*   Updated: 2017/01/11 16:31:06 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char *pnt;

	pnt = NULL;
	while (*s)
	{
		if (*s == (char)c)
			pnt = (char *)s;
		++s;
	}
	if (*s == (char)c)
		pnt = (char *)s;
	return (pnt);
}
