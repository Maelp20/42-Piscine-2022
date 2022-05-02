/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:57:22 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/10 11:38:59 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sign(int sign)
{
	if (sign % 2 == 0)
		return (1);
	if (sign % 2 != 0)
		return (-1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	final;

	i = 0;
	sign = 0;
	final = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		final = final * 10 + (str[i] - 48);
		i++;
	}
	sign = ft_sign(sign);
	final = final * sign;
	return (final);
}
