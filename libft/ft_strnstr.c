/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:30:39 by hdrumus           #+#    #+#             */
/*   Updated: 2017/01/11 16:30:40 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t ft_len;

	ft_len = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big && len >= ft_len)
	{
		if (ft_strncmp(big, little, ft_len) == 0)
			return ((char *)big);
		++big;
		--len;
	}
	return (NULL);
}
