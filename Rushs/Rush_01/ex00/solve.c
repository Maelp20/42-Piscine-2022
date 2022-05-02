/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:48:04 by fllanet           #+#    #+#             */
/*   Updated: 2022/02/13 18:47:56 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_soluce_check(int **board, int **entry);
int	ft_strlen(char *str);

int	ft_not_duplicate(int box, int nbr, int	**board)
{
	int		x;
	int		y;
	int		i;

	x = box / 4;
	y = box % 4;
	i = 0;
	while (i >= 0 && i <= box / 4 - 1)
	{
		if (board[i][y] == nbr)
			return (0);
		i++;
	}
	i = 0;
	while (i >= 0 && i <= box % 4 - 1)
	{
		if (board[x][i] == nbr)
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve(int **board, int box, int **entry)
{
	int		n;
	int		result;

	n = 1;
	result = 0;
	while (n <= 4 && result == 0)
	{
		if (ft_not_duplicate(box, n, board))
		{
			board[box / 4][box % 4] = n;
			if (box == 15)
				return (ft_soluce_check(board, entry));
			else
				result = ft_solve(board, box + 1, entry);
		}
		n++;
	}
	return (result);
}
