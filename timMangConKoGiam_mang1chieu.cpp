#include <stdio.h>

int a[100], n;
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
int timMax(int x[], int n){
	int max = x[0];
	for (int i=0; i<n; i++){
		if (x[i]>max)
			max = x[i];
	}
	return max;
}
void inMangConKoGiam (int x[], int n){
	int b[100];
	for (int i=0; i<n; i++){
		b[i] = 1;
	}
	for (int i = n-1; i>0; i--){
		if (x[i] >= x[i-1])
			b[i-1] = b[i] + 1;
		
	}
	printf("\nMang b: ");
	XuatMang(b,n);
	int soLuong = timMax(b,n);
	for (int i=0; i<n; i++){
		if(b[i] == soLuong) {
			printf("\nMang khong giam dai nhat: ");
			for (int j=i; j<soLuong+i; j++)
				printf("%d ", x[j]);
		}
	}
}
int main(){
	NhapMang(a,n);
	XuatMang(a,n);
	inMangConKoGiam(a,n);
	return 0;
}
