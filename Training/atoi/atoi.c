/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:22:45 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/23 17:33:34 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	nbr;
	int sign;

	nbr = 0;
	while (*str >= 9 && *str <= 13 || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	if (sign != 0)
		nbr = -nbr;
	return (nbr);
}

int main ()
{
	printf("mon atoi : %d\n", ft_atoi("  ---42a54"));
	printf("vrai atoi : %d\n", atoi("  ---42a54"));
}
