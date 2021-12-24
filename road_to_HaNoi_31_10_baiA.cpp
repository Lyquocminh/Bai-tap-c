#include <stdio.h>

int main(){
	int t;
	long long n;
	scanf("%d", &t);
	long long dem[t];
	for (int i = 0; i < t; i++){
		scanf("%d", &n);
		dem[i] = 1;
		do{
			n= n/2;
			dem[i]= dem[i]+1;
		}while (n >= 2);
	}
	for (int i = 0; i < t; i++)
		printf("\n%d", dem[i]);
	return 0;
}
