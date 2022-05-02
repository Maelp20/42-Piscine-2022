/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:31:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/18 13:56:27 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_rev_int_tab(char *tab, int size)
{
	int	i;
	int	j;
	int	buffer;

	i = 0;
	j = size - 1;
	buffer = 0;
	while (i < j)
	{
		buffer = tab[i];
		tab[i] = tab[j];
		tab [j] = buffer;
		i++;
		j--;
	}
}

void	ft_conv(int temp, char *dest, char *base_to, int len)
{
	if (temp < 0)
		temp = -temp;
	if (temp >= len)
		ft_conv(temp / len, &dest[1], base_to, len);
	dest[0] = base_to[temp % len];
}

int	ft_count(int temp, int len_base_to)
{
	int	size;

	if (temp < 0)
	{
		size = 2;
		temp = -temp;
	}
	else
		size = 1;
	while (temp >= len_base_to)
	{
		temp /= len_base_to;
		size++;
	}
	return (size);
}

char	*ft_putnbr_base(int temp, char *base_to, int len_base_to)
{
	int		size;
	char	*dest;

	size = ft_count(temp, len_base_to);
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	ft_conv(temp, dest, base_to, len_base_to);
	if (temp < 0)
		dest[size - 1] = '-';
	dest[size] = '\0';
	ft_rev_int_tab(dest, size);
	return (dest);
}
