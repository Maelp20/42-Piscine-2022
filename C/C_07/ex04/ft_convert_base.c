/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:31:48 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/23 18:39:26 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_putnbr_base(int temp, char *base_to, int len_base_to);

int	ft_sign(int sign)
{
	if (sign % 2 != 0)
		return (-1);
	return (1);
}

int	check_error(char *base)
{
	int	check;
	int	i;
	int	j;

	check = 0;
	while (base[check])
	{
		if ((base[check] == ' ') || (base[check] == '+') || (base[check] == '-')
			|| (base[check] >= 9 && base[check] <= 13))
			return (0);
		check ++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{	
	int	sign;
	int	temp;
	int	len_base_from;
	int	len_base_to;

	sign = 0;
	temp = 0;
	len_base_from = check_error(base_from);
	len_base_to = check_error(base_to);
	if (len_base_from <= 1 || len_base_to <= 1)
		return (0);
	while ((*nbr >= 9 && *nbr <= 13) || (*nbr == 32))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
		if (*nbr++ == '-')
			sign++;
	sign = ft_sign(sign);
	while ((ft_in_base(*nbr, base_from) >= 0) && *nbr)
	{
		temp = (temp * len_base_from) + ft_in_base(*nbr, base_from);
		nbr++;
	}
	temp = temp * sign;
	return (ft_putnbr_base(temp, base_to, len_base_to));
}
#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	printf("42:%s\n", ft_convert_base("", "0123456789abcdef", "0123456789"));
	printf("-2a:%s\n", ft_convert_base("-42", "0123456789", "0123456789abcdef"));
}
