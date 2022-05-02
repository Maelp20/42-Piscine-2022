/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:29:33 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/17 16:50:38 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	temp[127];
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		while ( i < 127)
		{
			temp[i] = 0;
			i++;
		}
		j = 1;
		while (j < argc)
		{
			i = 0;
			while (argv[j][i])
			{
				if (temp[(int)argv[j][i]] == 0)
				{
					write (1, &argv[j][i], 1);
					temp[(int)argv[j][i]] = 1;
				}
				i++;
			}
			j++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
