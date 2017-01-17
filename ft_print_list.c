/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:24:19 by rdavila           #+#    #+#             */
/*   Updated: 2017/01/16 13:50:39 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *list)
{
	if (list)
	{
		while (list)
		{
			ft_putstr(list->content);
			ft_putstr("(");
			ft_putnbr(list->content_size);
			ft_putstr(") ");
			list = list->next;
		}
	}
}
