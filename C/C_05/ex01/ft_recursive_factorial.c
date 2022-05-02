/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:13:11 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/14 14:27:08 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	long	n;

	n = nb;
	if (n < -1)
		return (0);
	if (n == 0)
		return (1);
	else
		n = n * ft_recursive_factorial(n - 1);
	return (n);
}
