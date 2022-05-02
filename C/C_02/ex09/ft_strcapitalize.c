/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:16:40 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/07 16:43:17 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alphanum(int j, char *str)
{
	if ((str[j] >= '0' && str[j] <= '9') || (str[j] >= 'A' && str[j] <= 'Z')
		|| (str[j] >= 'a' && str[j] <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (!(ft_str_is_alphanum(j, str)))
				str[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (ft_str_is_alphanum(j, str))
				str[i] = str [i] + 32;
		}
		i++;
		j++;
	}
	return (str);
}
