/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:56:22 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/12 22:04:03 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
/*
void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str);
}*/
void	last_word(char *str)
{
	int	i;
	int	start;
	int	end;
	//printf ("phrase : %s\n", str);

	while (*str && *str != 127 && (*str <= 13 || *str >= 32))
	{
		//printf ("str : %c\n", *str);
		str++;
	}
	if (*str >= 14 && *str <= 31)
		ft_putchar('\n');
	str--;
	//printf ("END : %c\n", *str);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str--;
	while (*str >= 33)
		str--;
	str++;
	//printf ("START : %c\n\n", *str);
	while (*str && *str >= 33)
	{
		ft_putchar(*str);
		str++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		last_word(argv[1]);
	}
}
