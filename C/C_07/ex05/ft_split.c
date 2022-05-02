/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:10:27 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/22 11:50:16 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_nbr(char *str, char *charset)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (!ft_in_charset(str[i], charset)
			&& (ft_in_charset(str[i + 1], charset)
				|| !str[i + 1]))
			nbr++;
		i++;
	}
	return (nbr);
}

int	ft_len(char *str, char *charset)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_in_charset(str[i], charset))
			return (i);
		i++;
	}
	return (i);
}

void	ft_splitnwrite(char **dest, char *str, char *charset, int nbr)
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	i = 0;
	while (i < nbr)
	{
		while (ft_in_charset(*str, charset))
			str++;
		if (!ft_in_charset(*str, charset))
		{
			len = ft_len(str, charset);
			temp = (char *)malloc(sizeof(char) * len + 1);
			j = -1;
			while (++j < len)
			{
				temp[j] = *str;
				str++;
			}
			dest[i] = temp;
		}
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		nbr;

	nbr = ft_check_nbr(str, charset);
	dest = (char **) malloc(sizeof(char *) * (nbr + 1));
	if (!dest)
		return (0);
	ft_splitnwrite(dest, str, charset, nbr);
	return (dest);
}
