/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:12:27 by seungcoh          #+#    #+#             */
/*   Updated: 2021/03/31 20:15:35 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char c)
{
	char p;

	write(1, "\\", 1);
	p = c / 16 + '0';
	write(1, &p, 1);
	p = c % 16 + '0';
	if (p > '9')
	{
		p += 39;
	}
	write(1, &p, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (32 <= str[i] && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
			print_hex(str[i]);
		i++;
	}
}
