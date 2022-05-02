/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_soluce_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:47:35 by fllanet           #+#    #+#             */
/*   Updated: 2022/02/13 18:47:36 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_left(int **board, int *left)
{
	int		i;
	int		x;
	int		y;
	int		max;

	y = 0;
	while (y < 4)
	{
		i = 1;
		x = 0;
		max = board[x][y];
		while (x < 4)
		{
			if (max < board[x][y])
			{
				max = board[x][y];
				i++;
			}
			x++;
		}
		if (i != left[y])
			return (0);
		y++;
	}
	return (1);
}

int	ft_right(int **board, int *right)
{
	int		i;
	int		x;
	int		y;
	int		max;

	y = 0;
	while (y < 4)
	{
		i = 1;
		x = 3;
		max = board[x][y];
		while (x >= 0)
		{
			if (max < board[x][y])
			{
				max = board[x][y];
				i++;
			}
			x--;
		}
		if (i != right[y])
			return (0);
		y++;
	}
	return (1);
}

int	ft_top(int **board, int *top)
{
	int		i;
	int		x;
	int		y;
	int		max;

	x = 0;
	while (x < 4)
	{
		i = 1;
		y = 0;
		max = board[x][y];
		while (y < 4)
		{
			if (max < board[x][y])
			{
				max = board[x][y];
				i++;
			}
			y++;
		}
		if (i != top[x])
			return (0);
		x++;
	}
	return (1);
}

int	ft_bot(int **board, int *top)
{
	int		i;
	int		x;
	int		y;
	int		max;

	x = 0;
	while (x < 4)
	{
		i = 1;
		y = 3;
		max = board[x][y];
		while (y >= 0)
		{
			if (max < board[x][y])
			{
				max = board[x][y];
				i++;
			}
			y--;
		}
		if (i != top[x])
			return (0);
		x++;
	}
	return (1);
}

int	ft_soluce_check(int **board, int **entry)
{
	if (ft_top(board, entry[0]) && ft_bot(board, entry[1])
		&& ft_left(board, entry[2]) && ft_right(board, entry[3]))
		return (1);
	else
		return (0);
	return (0);
}
