/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:01:38 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/24 15:36:50 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	if (c == 32 || c == 9 || c == 11)
		return(1);
	return (0); 
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= 'a' && av[i][j] <= 'z') && (!av[i][j-1] || is_space(av[i][j-1])))
				av[i][j] = av[i][j] - 32;
			else if ((av[i][j] >= 'A' && av[i][j] <= 'Z') && !is_space(av[i][j-1]))
				av[i][j] = av[i][j] + 32;
			write (1, &av[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
	if (ac == 1)
		write (1, "\n", 1);
	return (0);
}
