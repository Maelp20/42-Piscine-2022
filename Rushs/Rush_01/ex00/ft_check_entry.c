/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:44:22 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/13 18:44:26 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_entry(int argc, char **argv)
{
	int		x;
	int		y;

	x = 0;
	y = 1;
	if (ft_strlen(argv[1]) == 31 && argc == 2)
	{
		while (argv[1][x] >= '1' && argv[1][x] <= '4' && x <= 30)
			x += 2;
		while (argv[1][y] == ' ' && argv[1][y] && y <= 29)
			y += 2;
		if (!(x == 32 && y == 31))
			return (0);
	}
	else
		return (0);
	return (1);
}
