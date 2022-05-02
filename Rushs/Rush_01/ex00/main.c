/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:48:26 by fllanet           #+#    #+#             */
/*   Updated: 2022/02/13 18:46:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_error_message(void);
int		ft_solve(int **board, int box, int **entry);
int		ft_atoi(int **entry, char *argv);
void	ft_display_board(int **board);
int		**ft_init_board(void);
int		ft_check_entry(char argc, char **argv);
int		ft_free(int **board);

int	main(int argc, char **argv)
{
	int		**board;
	int		**entry;

	if (argc == 2)
	{
		if (!(ft_check_entry(argc, argv)))
			ft_error_message();
		else
		{
			entry = ft_init_board();
			board = ft_init_board();
			ft_atoi(entry, argv[1]);
			if (ft_solve(board, 0, entry))
				ft_display_board(board);
			else
				ft_error_message();
			if (entry)
				ft_free(entry);
			if (board)
				ft_free(board);
		}
	}
	else
		ft_error_message();
	return (0);
}
