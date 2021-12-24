#include <stdio.h>

void inMang(int x[], int n){
	printf("\nPhan tu cua mang: ");
	for (int i=0; i<n; i++){
		printf("%d", x[i]);
	}
}
void xoaPtuMang(int x[], int &n, int vitri){
	for (int i=vitri; i<n-1; i++){
		x[i] = x[i+1];
	}; n--;
}
int main() {
	int a[100], n, gt, vitri;
	do{
		printf("Nhap vao so luong phan tu (0<n<=100): ");
		scanf("%d", &n);
	}while (n<1 || n>100);
	
	for(int i=0; i<n;i++){
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
    }
    printf("Nhap vao gia tri can xoa: ");
    scanf("%d", &gt);
    for (int i=0; i<n; i++){
    	if (a[i] == gt) vitri = i;
	}
	xoaPtuMang(a,n,vitri);
	inMang(a,n);
	return 0;
}
    
