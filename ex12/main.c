/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungcoh <seungcoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:51:56 by seungcoh          #+#    #+#             */
/*   Updated: 2021/03/31 20:40:31 by seungcoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void *ft_print_memory(void *addr, unsigned int size);
int	main(void)
{
	char a[] = "Bonjour les amin";
	char b[] = "ches   c  est fo";
	b[4]=9;
	b[5]=10;
	b[6]=9;
	char c[] = "kklol.lolk k";
	c[0]=10;
	c[1]=9;
	c[9]=10;
	c[11]=0;
	char d[] = "udtoutdce qu on ";
	d[1]=9;
	d[6]=9;
	char e[] = "peut faire avec ";
	e[15]=9;
	char f[] = "  print_memory  ";
	f[0]=10;
	f[1]=9;
	f[14]=10;
	f[15]=10;
	ft_print_memory(a, 16);
//	printf("%ld\n",(unsigned long)a);
	ft_print_memory(b, 16);
//	printf("%ld\n",(unsigned long)b);
	ft_print_memory(d, 16);
//	printf("%ld\n",(unsigned long)d);
	ft_print_memory(e, 16);
//	printf("%ld\n",(unsigned long)c);
	ft_print_memory(f, 16);
	ft_print_memory(c, 12);
	ft_print_memory("",0);
}
