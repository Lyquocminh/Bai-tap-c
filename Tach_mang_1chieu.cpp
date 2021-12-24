#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int a[100], b[100], c[100];
int n1,n2,n3;
void NhapMang(int x[], int &n){
	do {
		printf("Nhap vao so luong ptu (0<n<=100): ");
		scanf("%d", &n);
	}while(n<0||n>100);
	for (int i=0; i<n; i++){
		printf("a[%d]= ", i);
		scanf("%d", &x[i]);
	}
}
void XuatMang(int x[], int n){
	printf("Gia tri cua mang la: ");
	for(int i=0; i<n; i++){
		printf("%d ", x[i]);
	}
	printf("\n");	
}
void tachMang(int x[100],int n,int x2[100],int &n2, int x3[100], int &n3){
	n2 = 0, n3 = 0;
	for (int i=0; i<n;i++){
		if (x[i] %2== 1){
			x2[n2] = x[i];
			n2++;
		}else { 
		    x3[n3] = x[i];
			n3++;
		}
	}
}
int main(){
	NhapMang(a,n1);
	printf("\n------Mang Nguon-------\n");
	XuatMang(a,n1);
	printf("\n-------Mang Le------\n");
	tachMang(a,n1,b,n2,c,n3);
	XuatMang(b,n2);
	printf("\n------Mang Chan------\n");
	XuatMang(c,n3);
	return 0;
}
