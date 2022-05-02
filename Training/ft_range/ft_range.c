/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:52:00 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/24 13:08:05 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	range;
	int	*tab;
	int	i;

	if (end > start)
		range = end - start + 1;
	else
		range = start - end + 1;
	tab = (int *)malloc(sizeof(int) * range);
	if (!tab)
		return NULL;
	i = 0;
	while (i < range)
	{
		tab[i] = start;
		if (start > end)
			start--;
		else
			start++;
		i++;
	}
	i = 0;
	while (i < range)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
	return (tab);
}

int main ()
{
	ft_range(5, 2);
}
