/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:14:09 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/23 15:26:52 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_nb_words(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (!ft_is_space(str[i]) && (ft_is_space(str[i + 1]) || !str[i + 1]))
			nb++;
		i++;
	}
	return (nb);
}

int	ft_len(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_is_space(str[i]))
			return (i);
		i++;
	}
	return (i);
}
void	ft_splitnfill(char *str, char **dest, int nb_words)
{
	char	*temp;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < nb_words)
	{
		while (ft_is_space(*str))
			str++;
		if (!ft_is_space(*str))
		{
			len = ft_len(str);
			temp = (char *)malloc(sizeof(char) * len + 1);
			j = -1;
			while (++j < len)
			{
				temp[j] = *str;
				str++;
			}
			dest[i] = temp;
			printf("dest[%d] : %s\n", i, dest[i]);
		}
		i++;
	}
	dest[i] = 0;
}

char **ft_split(char *str)
{
	char	**dest;
	int	nb_words;

	nb_words = ft_nb_words(str);
	dest = (char **)malloc(sizeof(char) * nb_words + 1);
	if (!dest)
		return (NULL);
	ft_splitnfill(str, dest, nb_words);
	return(dest);
}

int	main (int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_split("comment sa va");
}
