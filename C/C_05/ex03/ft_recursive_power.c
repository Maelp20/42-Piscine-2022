/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:13:11 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/14 14:26:51 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	long	n;
	long	p;

	n = nb;
	p = power;
	if (p == 0)
		return (1);
	if (nb == 0 || p < 0)
		return (0);
	else
		n = n * ft_recursive_power(n, (p - 1));
	return (n);
}
