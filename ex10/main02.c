#include<stdio.h>
unsigned int	ft_strlcpy(char *dest,char *stc, unsigned int n);
int main()
{
	char a[]="asjdklasj";
	char b[]="2389048290342";
	printf("%d %s",ft_strlcpy(a,b,8),a);
}
