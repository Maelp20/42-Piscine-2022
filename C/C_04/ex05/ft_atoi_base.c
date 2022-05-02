/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:33:06 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/10 13:00:49 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (1);
		check ++;
	}
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

int	ft_atoi_base(char *str, char *base)
{	
	int		sign;
	long	final;
	int		x;

	sign = 0;
	final = 0;
	x = 0;
	if (check_error(base))
		return (0);
	while (base[x])
		x++;
	if (x <= 1)
		return (0);
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign++;
	sign = ft_sign(sign);
	while ((ft_in_base(*str, base) >= 0) && *str)
	{
		final = (final * x) + ft_in_base(*str, base);
		str++;
	}
	return (final * sign);
}
