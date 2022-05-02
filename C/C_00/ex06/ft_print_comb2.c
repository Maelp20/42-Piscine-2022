/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:33:05 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/04 10:59:27 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 100)
	{	
		b = a + 1;
		while (b < 100)
		{
			ft_putchar('0' + a / 10);
			ft_putchar('0' + a % 10);
			write (1, " ", 1);
			ft_putchar('0' + b / 10);
			ft_putchar('0' + b % 10);
			b++;
			if (a != 98)
				write (1, ", ", 2);
		}
		a++;
	}
}
