/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:31:52 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/03 18:52:47 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char i, char x, char z)
{
	write(1, &i, 1);
	write(1, &x, 1);
	write(1, &z, 1);
}

void	ft_putspace(void)
{
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '/';
	while (++a <= '7')
	{
		b = a;
		while (++b <= '8')
		{
			c = b;
			while (++c <= '9')
			{
				ft_putchar(a, b, c);
				if (a != '7')
				{
					ft_putspace();
				}
			}
		}
	}
}
