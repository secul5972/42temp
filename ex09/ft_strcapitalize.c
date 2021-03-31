/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:15:03 by seungcoh          #+#    #+#             */
/*   Updated: 2021/03/29 21:51:49 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_first(char *c, int flag)
{
	if ('a' <= *c && *c <= 'z')
	{
		*c -= 32;
		flag = 0;
	}
	else if ('A' <= *c && *c <= 'Z')
	{
		flag = 0;
	}
	else if ('0' <= *c && *c <= '9')
	{
		flag = 0;
	}
	else
	{
		flag = 1;
	}
	return (flag);
}

int		check_second(char *c, int flag)
{
	if ('A' <= *c && *c <= 'Z')
	{
		*c += 32;
	}
	else if ('a' <= *c && *c <= 'z')
	{
		flag = 0;
	}
	else if ('0' <= *c && *c <= '9')
	{
		flag = 0;
	}
	else
	{
		flag = 1;
	}
	return (flag);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (flag)
		{
			flag = check_first(str + i, flag);
		}
		else
		{
			flag = check_second(str + i, flag);
		}
		i++;
	}
	return (str);
}
