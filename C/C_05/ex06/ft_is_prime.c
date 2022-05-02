/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:03:56 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/14 20:00:27 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		n;
	int		r;

	n = nb;
	r = 1;
	if (n == 0)
		return (0);
	while (r * r < n && r < 46341)
		r++;
	return (r);
}

int	ft_is_prime(int nb)
{
	long	n;
	long	i;
	int		root;

	n = nb;
	i = 2;
	root = ft_sqrt(nb);
	if (n <= 1)
		return (0);
	if (n == 2 || n == 3)
		return (1);
	while (n % i != 0 && i < n - 1 && i <= root)
		i++;
	if (n % i == 0)
		return (0);
	else
		return (1);
}
