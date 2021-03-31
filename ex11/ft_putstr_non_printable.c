/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:12:27 by seungcoh          #+#    #+#             */
/*   Updated: 2021/03/29 22:38:36 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			write(1, "\\", 1);
			c = str[i] / 16 + '0';
			write(1, &c, 1);
			c = str[i] % 16 + '0';
			if (c - '0' >= 10)
			{
				c = c - 10 + 'a' - '0';
			}
			write(1, &c, 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
