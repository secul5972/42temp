/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:51:46 by seungcoh          #+#    #+#             */
/*   Updated: 2021/03/29 21:08:08 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (str[i] != '\0')
	{
		if (!(32 <= str[i] && str[i] <= 126))
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
