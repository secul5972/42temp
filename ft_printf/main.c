#include "ft_printf.h"
#include <stdio.h>


int main(){
	char c = 'd';
	char s[10] = "dddffff";
	/*printf("[%c]sdfsdf[%3.4s]dfdfsdf\n",c,s);
	ft_printf("[%c]sdfsdf[%3.4s]dfdfsdf\n",c,s);
	printf("[%c]sdfsdf[%6.4s]dfdfsdf\n",c,s);
	ft_printf("[%c]sdfsdf[%6.4s]dfdfsdf\n",c,s);
	printf("[%c]sdfsdf[%3.10s]dfdfsdf\n",c,s);
	ft_printf("[%c]sdfsdf[%3.10s]dfdfsdf\n",c,s);
	printf("[%c]sdfsdf[%12.10s]dfdfsdf\n",c,s);
	ft_printf("[%c]sdfsdf[%12.10s]dfdfsdf\n",c,s);
	printf("[%-c]sdfsdf[%-12.10s]dfdfsdf\n",c,s);
	ft_printf("[%-c]sdfsdf[%-12.10s]dfdfsdf\n",c,s);
	printf("[%0c]sdfsdf[%03.4s]dfdfsdf\n",c,s);
	ft_printf("[%0c]sdfsdf[%03.4s]dfdfsdf\n",c,s);*/

	printf("ddfsd[%10.3d]k\n", 2000);
	ft_printf("ddfsd[%10.3d]k\n", 2000);
	printf("ddfsd[%10.5d]k\n", 200);
	ft_printf("ddfsd[%10.5d]k\n", 200);
	printf("ddfsd[%010d]k\n", 200);
	ft_printf("ddfsd[%010d]k\n", 200);
	printf("ddfsd[%10.13d]k\n", 200);
	ft_printf("ddfsd[%10.13d]k\n", 200);
	printf("ddfsd[%-*.2d]d\n", 10, 200);
	ft_printf("ddfsd[%-*.2d]d\n", 10,200);
	printf("ddfsd[%-*.5d]d\n", 10, 200);
	ft_printf("ddfsd[%-*.5d]d\n", 10,200);
	printf("ddfsd[%*.2d]d\n", 10, 200);
	ft_printf("ddfsd[%*.2d]d\n", 10,200);
	printf("ddfsd[%*.5d]d\n", 10, 200);
	ft_printf("ddfsd[%*.5d]d\n", 10,200);

	printf("ddfsd[%-*.2u]u\n", 10, 200);
	ft_printf("ddfsd[%-*.2u]u\n", 10,200);
	printf("ddfsd[%-*.5u]u\n", 10, 200);
	ft_printf("ddfsd[%-*.5u]u\n", 10,200);
	printf("ddfsd[%*.2u]u\n", 10, 200);
	ft_printf("ddfsd[%*.2u]u\n", 10,200);
	printf("ddfsd[%*.5u]u\n", 10, 200);
	ft_printf("ddfsd[%*.5u]u\n", 10,200);

	//printf("x[%-*.5x]x\n", 10, 200);

}