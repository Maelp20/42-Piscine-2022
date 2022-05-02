/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:11:15 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/18 11:47:54 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
		nbr = - nbr;
	while (nbr > 0)
	{
		len = len + 1;
		nbr = nbr / 10;
	}
	return (len);
}
char	*ft_itoa(int nbr)
{
	char	*tab;
	int	len;

	len = ft_nbr_len(nbr);
	tab = malloc (sizeof(char) * (len + 1));
	tab[len + 1] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		while (len > 0)
		{
			tab[len - 1] = nbr % 10 + 48;
			nbr /= 10;
			len--;
		}
		tab[0] = '-';
	}
	else
	{
		while (len > 0)
		{
			tab[len - 1] = nbr % 10 + 48;
			nbr /= 10;
			len--;
		}
	}
	return (tab);
}

int main ()
{
	int nbr;

	nbr = 42;
	printf("%s\n", ft_itoa(nbr));
}
