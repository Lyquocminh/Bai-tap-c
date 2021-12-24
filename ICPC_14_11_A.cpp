#include <stdio.h>
#include <string.h>

void xoaPtuMang(char x[], int &n, int vitri){
	for (int i=vitri; i<n-1; i++){
		x[i] = x[i+1];
	}; n--;
}
void themGiaTri (char a[], int &n, char x, int p){
	n = n+1;
	for (int i = n - 1; i >= p; i--)
		a[i]=a[i-1];
	a[p] = x;
}
int stop(char a[], char b[]){
	int dai_a = strlen(a), dai_b = strlen(b);
	if (dai_a < dai_b)
		return 0;
	for (int i = 0; i < dai_a; i++)	
		for (int j = 0; j < dai_b; i++)
			if (a[i]==b[j]){
				xoaPtuMang(a,dai_a,i);
				xoaPtuMang(b,dai_b,j);
				j--;
				i--;
			}
	if (dai_a==0)
		return 1;
	return 0;
}
int main(){
	char s[1000];
	scanf("%s", &s);
	int dai = strlen(s);
	char c[1000];
	for (int i = 0; i < dai; i++)
		c[i]=s[i];
	int kt = strlen(c);
	for (int i = 0; i < kt; i++){
		if (c[i]==c[i+1]){
			xoaPtuMang(c,kt,i);
			i--;
		}
	}
	int soKt;
	scanf("%d", &soKt);
	if (soKt < kt)
		printf("-1");
	char a[kt];
	for (int i = 0; i < kt; i++)
		a[i]=c[i];
	while (stop == 0){
		if (soKt == kt)
			for (int i = 0; i < kt; i+=2)
				themGiaTri(a,kt,i+1,a[i]);
	}
	return 0;
}
