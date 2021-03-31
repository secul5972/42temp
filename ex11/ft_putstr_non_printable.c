/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:12:27 by seungcoh          #+#    #+#             */
/*   Updated: 2021/03/31 17:08:21 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char h)
{
	char p;

	write(1, "\\", 1);
	p = h / 16 + '0';
	write(1, &p, 1);
	p = h % 16;
	if (p > 9)
	{
		p -= 10;
		p += 'a';
	}
	else
	{
		p += '0';
	}
	write(1, &p, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			print_hex(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
