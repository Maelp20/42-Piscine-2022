/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:38:32 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/24 12:58:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_value_len(int value, int base)
{
	int	len;

	len = 0;
	if (value < 0)
		value = -value;
	while (value > 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *str)
{
	int	i;
	char *cpy;

	i = 0;
	while (str[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * i + 1);
	if (!cpy)
		return(NULL);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	return (cpy);
}

char *ft_itoa_base(int value, int base)
{
	int	i;
	int		len;
	char	*dest;
	char	mybase[16] = "0123456789ABCDEF";

	if (value == 0)
		return (ft_strdup("0"));
	if (base == 10 && value == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_value_len(value, base);
	if (base == 10 && value < 0)
		i = 1;
	else
		i = 0;
	dest = (char*)malloc(sizeof(char) * len + 1 + i);
	if (!dest)
		return (NULL);
	if (i == 1)
	{
		dest[0] = '-';
		len++;
	}
	mybase[base] = '\0';
	dest[len] = '\0';
	if (value < 0)
		value = -value;
	while (len > i)
	{
		dest[len - 1] = mybase[value % base];
		value = value / base;
		len--;
	}
	return (dest);
}

int	main()
{
	printf ("RESULT: %s\n", ft_itoa_base(24, 2));
	printf ("RESULT: %s\n", ft_itoa_base(42, 8));
	printf ("RESULT: %s\n", ft_itoa_base(42, 16));
	printf ("RESULT: %s\n", ft_itoa_base(42, 12));
	printf ("RESULT: %s\n", ft_itoa_base(0, 10));
	printf ("RESULT: %s\n", ft_itoa_base(-2147483648, 10));
}
