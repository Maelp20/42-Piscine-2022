/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:32:28 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/14 14:30:12 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

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

int	**ft_init_board(void)
{
	int		x;
	int		y;
	int		**board;

	x = 0;
	board = malloc(sizeof(int *) * 10);
	if (!board)
		return (0);
	while (x < 10)
	{
		board[x] = malloc((sizeof(int) * 10));
		if (!board[x])
			return (0);
		x++;
	}
	x = 0;
	while (x < 10)
	{
		y = -1;
		while (y++ < 10)
			board[x][y] = 0;
		x++;
	}
	return (board);
}

int	**ft_ten_queens_puzzle(void)
{
	int	**board;

	board = ft_init_board();
	ft_display_board(board);
	return (board);
}
