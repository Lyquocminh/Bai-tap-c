#include <stdio.h> 

int main() {
	unsigned long n,x,du;
	int b, gdc = 0;
	scanf("%d", &n);
	int i = n;
	for (; i<n+10000;i++){
		du = i;
		b=0;
		do {
			b = du%10 + b;
			du=du/10;
		}while(du/1!=0) ;
		int j = 2;
		for(; j<b; j++){
			if (b % j == 0 && i % j == 0){
				gdc = i;
				break;
			}
		}
		if (gdc != 0){
			printf("%d", gdc);
			break;
		}
	}
	return 0;

}
