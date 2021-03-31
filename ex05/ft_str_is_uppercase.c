/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:51:46 by seungcoh          #+#    #+#             */
/*   Updated: 2021/03/29 20:11:15 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (str[i] != '\0')
	{
		if (!('A' <= str[i] && str[i] <= 'Z'))
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
