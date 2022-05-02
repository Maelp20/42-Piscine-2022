/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:25:36 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/18 13:54:31 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*tab;
	int		range;
	int		j;
	long	mx;
	long	mn;

	mx = max;
	mn = min;
	if (mn >= mx)
		return (NULL);
	range = mx - mn;
	tab = malloc(sizeof(int *) *(range));
	if (!tab)
		return (NULL);
	j = 0;
	while (mn < mx)
	{
		tab[j] = mn;
		j++;
		mn++;
	}
	return (tab);
}
