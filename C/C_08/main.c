/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:10:11 by mpignet           #+#    #+#             */
/*   Updated: 2022/02/21 12:10:13 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);

int					main(int argc, char **argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
}
