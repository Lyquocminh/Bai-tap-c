#include <stdio.h>

int timMin(int x[], int n){
	int min = x[0];
	for(int i=1; i<n;i++){
	    if (min>x[i]) min=x[i];
    }
	return min;
}
int timMax(int x[], int n){
	int max = x[0];
	for (int i=1; i<n; i++){
	    if (max<x[i]) max=x[i];
    }
	return max;
}
int main() {
	int a[100], n;
	do{
		printf("Nhap vao so luong phan tu (0<n<=100): ");
		scanf("%d", &n);
	}while (n<1 || n>100 );
	
	for (int i=0; i<n;i++){
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
	printf("Max = %d", timMax(a, n));
	printf("\nMin = %d", timMin(a, n));
	return 0;
}
