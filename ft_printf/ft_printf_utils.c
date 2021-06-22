/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:42:58 by seungcoh          #+#    #+#             */
/*   Updated: 2021/06/22 21:21:12 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_max(const int a, const int b)
{
	if (a > b)
		return (a);
	else return (b);
}

int ft_min(const int a, const int b)
{
	if (a < b)
		return (a);
	else return (b);
}