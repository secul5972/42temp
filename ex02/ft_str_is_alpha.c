/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:51:46 by seungcoh          #+#    #+#             */
/*   Updated: 2021/03/29 20:03:21 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (str[i] != '\0')
	{
		ret = 0;
		if ('a' <= str[i] && str[i] <= 'z')
		{
			ret = 1;
		}
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			ret = 1;
		}
		if (!ret)
		{
			break ;
		}
		i++;
	}
	return (ret);
}
