/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrumus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:18:29 by hdrumus           #+#    #+#             */
/*   Updated: 2017/01/11 16:18:31 by hdrumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_size(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_copy(char *aux, int nb, int i, int len)
{
	if (nb == -2147483648)
	{
		aux[0] = '-';
		aux[1] = '2';
		ft_copy(aux, 147483648, 2, len + 1);
		return ;
	}
	if (nb < 0)
	{
		aux[i++] = '-';
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_copy(aux, nb / 10, i + 1, len);
		aux[len - i] = nb % 10 + '0';
	}
	else
		aux[len - i] = nb + '0';
}

char		*ft_itoa(int n)
{
	char	*aux;
	int		len;

	len = ft_size(n);
	aux = (char*)malloc(len + 1);
	if (aux == NULL)
		return (NULL);
	if (n >= 0)
		ft_copy(aux, n, 0, len - 1);
	else
		ft_copy(aux, n, 0, len);
	aux[len] = '\0';
	return (aux);
}
