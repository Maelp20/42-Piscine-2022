/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:13:11 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/14 17:01:16 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	long	n;

	n = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (n > 1)
	{
		nb = nb * (n - 1);
		n--;
	}
	return (nb);
}
