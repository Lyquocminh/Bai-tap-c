#include <stdio.h>
#include <string.h>
int main(){
	char p[100000];	
	scanf("%s", &p);
	int dai = strlen(p);
	char s[dai];
	if (dai%2==0)
		for (int i = 0; i <= dai; i++)
			i%2==0?s[i]=p[dai/2-1-(i/2)]:s[i]=p[dai/2+(i/2)];
	else 
		for (int i = 0; i <= dai; i++)
			i%2==0?s[i]=p[dai/2-(i/2)]:s[i]=p[dai/2+(i/2)+1];
	printf("%s", s);
	return 0;
}
