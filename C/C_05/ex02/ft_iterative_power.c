/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:13:11 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/14 14:27:41 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	long	n;
	long	p;

	n = nb;
	p = power;
	if (p == 0)
		return (1);
	if (n == 0 || p < 0)
		return (0);
	while (p > 1)
	{
		p--;
		n = n * nb ;
	}
	return (n);
}
