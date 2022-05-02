/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:13:34 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/24 14:46:35 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_error(const char *str)
{
	int	i;

	i = 0;
	if (str[0] != '-' || !(str[0] >= '0' && str[0] <= '9') || !(str[0] >= 'a' && str[0] <= 'z') || !(str[0] >= 'A' && str[0] <= 'Z'))
		return (1);
	i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') || !(str[i] >= 'a' && str[i] <= 'z') || !(str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		if (c <= 'A' && c<= 'Z')
		{
			if (c == (base[i] - 32))
				return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	nb;
	char base[16] = "0123456789abcdef";

	base[str_base] = '\0';
	if (check_error(str))
		return (0);
	i = 0;
	nb = 0;
	while (str[i] && ft_in_base(str[i], base) >= 0)
	{
		nb = nb * str_base + ft_in_base(str[i], base);
		i++;
	}
	if (str[0] == '-')
		nb = -nb;
	return (nb);
}
