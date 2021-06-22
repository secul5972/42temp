#include "ft_printf.h"
#include <stdio.h>


int main(){
	char c = 'd';
	char s[10] = "dddffff";
	/*printf("%c\n", c);
	ft_printf("%0-4cy", c);
	printf("\n");
	ft_printf("%4cy", c);
	printf("\n");
	ft_printf("%s", s);*/
	printf("\n%3.4s\n",s);
	ft_printf("%12.6s", s);
	printf("\n");
}