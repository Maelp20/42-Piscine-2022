/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:38:02 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/24 14:44:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_error(const char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-' && !(str[0] >= '0' && str[0] <= '9') && !(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z'))
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}
int	ft_in_base(char c, char *base)
{
	int i ;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		if (c >= 'A' && c <= 'Z')
			if (c == (base[i] - 32))
				return (i);
		i++;
	}
	return (-1);
}
int	ft_atoi_base(const char *str, int str_base)
{
	int	nb;
	int i ;
	char	base[16] = "0123456789abcdef";

	if (check_error(str))
		return (0);
	base[str_base] = '\0';
	printf("Base : %s\n", base);
	i = 0;
	nb = 0;
	while (str[i] && ft_in_base(str[i], base) >= 0)
	{
		nb = (nb * str_base) + ft_in_base(str[i], base);
		i++;
	}
	if (str[0] == '-')
		nb = -nb;
	return (nb);
}
	
int	main(void)
{
	printf("42:%d\n", ft_atoi_base("2450", 1));
	printf("-42:%d\n", ft_atoi_base("-2a", 16));
	printf("42:%d\n", ft_atoi_base("2a", 16));
	printf("0:%d\n", ft_atoi_base("   --------+- 2a", 16));
	printf("0:%d\n", ft_atoi_base("   --------+-z", 16));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", 2));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", 1));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", 1));
	printf("0:%d\n\n", ft_atoi_base("   --------+-2a", 0));
	const char str[] = "2a";
	int	size = 16;

	printf("RESULT : %d\n", ft_atoi_base(str, size));

}
