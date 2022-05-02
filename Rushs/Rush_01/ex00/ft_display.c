/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:47:18 by fllanet           #+#    #+#             */
/*   Updated: 2022/02/13 14:28:09 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_display_board(int **entry)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_putchar(entry[x][y] + 48);
			if (!(x == 3))
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
