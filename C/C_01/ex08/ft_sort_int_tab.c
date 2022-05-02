/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:45:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/06 17:07:11 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int i, int j, int *tab)
{
	int	temp;

	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (size == 1)
		return ;
	while (i < size - 1)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				swap(i, j, tab);
				j = i + 1;
			}
			else
				j++;
		}
		i++;
		j = i + 1;
	}
}
