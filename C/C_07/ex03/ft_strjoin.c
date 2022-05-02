/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:07:52 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/22 12:18:35 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	total_len(char **strs, char *sep, int size)
{
	int	i;
	int	len;
	int	seplen;

	i = 0;
	len = 0;
	seplen = ft_strlen(sep);
	while (i < size)
	{
		len = len + ft_strlen(strs[i]) + seplen;
		i++;
	}
	return (len);
}

void	ft_strcat(char *dest, char **strs, char *sep, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			*dest = strs[i][j];
			dest++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			*dest = sep[j];
			dest++;
			j++;
		}
		i++;
	}
	return ;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*dest;
	int		len;

	len = total_len(strs, sep, size);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	if (size == 0)
	{
		dest[0] = 0;
		return (dest);
	}
	while (i < len)
	{
		dest[i] = 0;
		i++;
	}
	ft_strcat(dest, strs, sep, size);
	dest[len] = '\0';
	return (dest);
}
