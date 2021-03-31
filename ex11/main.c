#include<stdio.h>
void ft_putstr_non_printable(char *str);
int main(){
	char a[]="dfsdkjh";
	char b[]="Coucou tu vas bien ?";
	a[0]=127;
	a[1]=31;
	a[2]=56;
	a[3]='d';
	a[4]='v';
	a[5]=3;
	a[6]=31;
	b[7]='\n';
	ft_putstr_non_printable(b);
}
