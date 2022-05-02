/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othersplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:47:18 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/24 16:20:48 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_space (char c)
{
	if (c == 32 || c == 9 || c == 11)
		return (1);
	return (0);
}

int	ft_count(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if(!is_space(str[i]) && (is_space(str[i + 1]) || !str[i + 1]))
			nb++;
		i++;
	}
	return (nb);
}

int	ft_len(char *str)
{
	int	len;

	len = 1;
	while (str[len])
	{
		if(is_space(str[len])
			return (len);
		len++;
	}
	return (len);
}

void	ft_splitnfill(char *str, char **dest, nb_words)
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	i = 0;
	while(i < nb_words)
	{
		while (is_space(*str))
			str++;
		if (!is_space(*str))
		{
			len = ft_len(str);
			temp = (char*)malloc(sizeof(char) * len + 1);
			if (!temp)
				return(NULL);
			j = -1;
			while (++j < len)
			{
				temp[j] = str;
				str++;
			}
			dest[i] = temp;
		}
		i++;	
	}
	dest[i] = 0;
}

char **ft_split(char *str)
{
	int		i;
	int		nb_words;
	char	**dest;

	nb_words = ft_count(char*str);
	dest = (char**)malloc(sizeof(char) * nb_words + 1);
	if (!dest)
		return (NULL);
	ft_splitnfill(str, dest, nb_words);
	return (dest);
}
