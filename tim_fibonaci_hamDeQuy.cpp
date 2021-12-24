#include <stdio.h>
int fibonaci (int x){
	if (x==0) return 0;
	else if (x==1) return 1;
	else return fibonaci(x-1)+fibonaci(x-2);
}
int main() {
	int n;
	do {
		printf("Nhap vao so nguyen n = ");
		scanf("%d", &n);
	}while (n<0);
	printf("Fibonaci(%d) = %d", n, fibonaci(n));
	return 0;
}
