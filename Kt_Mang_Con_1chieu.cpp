#include <stdio.h>

int a[100], b[100], n,m;
void NhapMang (int x[], int &n){
	do{
		printf("Nhap so luong phan tu (0<n<=100): ");
		scanf("%d", &n);
	}while (n<1||n>100);
	for (int i=0; i<n; i++ ){
		printf("x[%d] = ", i);
		scanf("%d", &x[i]);
	}
}
void XuatMang(int x[], int n){
	printf("Gia tri cua mang la: ");
	for (int i=0; i<n; i++){
		printf("%d ", x[i]);
	}
}
int KiemTra (int x1[], int n, int x2[], int m){
	int kq = 0;
	if (n >= m){
		for (int i = 0; i<n; i++){
			if (x1[i] = x2[0]){
				int j=0;
				for(; j<m; j++){
					if (x1[i+j] != x2[j])
						break;
				}
				if (j==m) 
					kq = 1;
			}
		}
	}
	return kq;
}
int main () {
	NhapMang(a,n);
	XuatMang(a,n);
	printf("\n-----------\n");
	NhapMang(b,m);
	XuatMang(b,m);
	printf("\n-----------\n");
	int kt = KiemTra(a,n,b,m);
	if (kt == 0)
		printf("Mang b ko phai la con cua mang a");
	else 
		printf("Mang b la con cua mang a");
	return 0;
}
