/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:47:35 by fllanet           #+#    #+#             */
/*   Updated: 2022/02/13 14:20:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**ft_init_board(void)
{
	int		x;
	int		y;
	int		**board;

	x = 0;
	board = malloc(sizeof(int *) * 4);
	if (!board)
		return (0);
	while (x < 4)
	{
		board[x] = malloc((sizeof(int) * 4));
		if (!board[x])
			return (0);
		x++;
	}
	x = 0;
	while (x < 4)
	{
		y = -1;
		while (y++ < 4)
			board[x][y] = 0;
		x++;
	}
	return (board);
}

int	ft_free(int **board)
{
	int		i;

	i = -1;
	while (i++ < 4)
		free(board[i]);
	free(board);
	return (0);
}
