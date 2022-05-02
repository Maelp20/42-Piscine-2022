/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:28:40 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/13 12:18:19 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write (1, &c[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while ((s1[a] != '\0') && (s1[a] == s2[a]))
		a++;
	return (s1[a] - s2[a]);
}

void	ft_sort_str_tab(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (size == 1)
		return ;
	while (i < size - 1)
	{
		while (j < size)
		{		
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				swap(&tab[i], &tab[j]);
				j = i + 1;
			}
			else
				j++;
		}
		i++;
		j = i + 1;
	}
}

int	main(int argc, char **argv)
{
	int	cpt;

	cpt = 1;
	ft_sort_str_tab(argv, argc);
	while (cpt < argc)
	{
		ft_putstr(argv[cpt]);
		cpt++;
	}
	return (0);
}
