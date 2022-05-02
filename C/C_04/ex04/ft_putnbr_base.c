/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:33:06 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/10 14:37:11 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_samechar(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(char *base)
{
	int	check;

	check = 0;
	if (base[0] == 0)
		return (1);
	while (base[check] != 0)
	{
		if ((base[check] == ' ') || (base[check] == '+') || (base[check] == '-')
			|| (base[check] >= 9 && base[check] <= 13))
			return (1);
		check ++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_conv_print(long a, int size, char *base)
{
	if (a > size - 1)
		ft_conv_print(a / size, size, base);
	ft_putchar(base[a % size]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		x;
	long	n;

	x = 0;
	n = nbr;
	if (check_error(base) || check_samechar(base))
		return ;
	while (base[x])
		x++;
	if (x <= 1)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		ft_conv_print(-n, x, base);
	}
	else
		ft_conv_print(n, x, base);
}
