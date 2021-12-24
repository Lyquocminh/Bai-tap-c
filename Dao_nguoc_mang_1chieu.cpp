#include <stdio.h>
void inMang(int x[], int n) {
	printf("\nGia tri cua mang la: ");
	for (int i=0; i<n; i++){
		printf("%d", x[i]);
	}
}
void inMangNguoc(int x[],int n){
	printf("\nMang dao nguoc la: ");
	for (int i=n-1; i>=0; i--){
		printf("%d", x[i]);
	}
}
int main() {
	int a[100], n;
	do{
		printf("Nhap vao so luong phan tu (0<n<=100): ");
		scanf("%d", &n);
	}while (n<1 || n>100);
	
	for(int i=0; i<n;i++){
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
    } 
	inMang(a,n);
	inMangNguoc(a,n);
	return 0;
}
