/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:51:46 by seungcoh          #+#    #+#             */
/*   Updated: 2021/03/29 20:07:44 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (str[i] != '\0')
	{
		if (!('a' <= str[i] && str[i] <= 'z'))
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
