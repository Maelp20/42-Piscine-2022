/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:38:43 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/18 13:46:08 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*newstr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	newstr = malloc(sizeof(*src) *(i + 1));
	if (!newstr)
		return (NULL);
	return (ft_strcpy(newstr, src));
}
