#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int a[100], b[100], c[200], n1,n2,n3;
void NhapMang(int x[], int &n){
	do {
		printf("Nhap vao so luong ptu (0<n<=100): ");
		scanf("%d", &n);
	}while(n<0||n>100);
	for (int i=0; i<n; i++){
		printf("a[%d]", i);
		scanf("%d", &x[i]);
	}
}
void XuatMang(int x[], int n){
	printf("Gia tri cua mang la: ");
	for(int i=0; i<n; i++){
		printf("%d", x[i]);
	}
	printf("\n");
	
}
void sxTangDan(int x[], int n){
	for (int i=0; i<n-1;i++){
		for (int j=i+1; j<n;j++){
			if(x[i]>x[j]) {
				int temp = x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
	}
}
void tronMang(int x1[],int n_x1,int x2[],int n_x2,int x3[],int &n_x3){
	n_x3 = n_x1+n_x2;
	int i1 =0, i2=0, i3=0;
	while (i3<n_x3){
		if (i1>=n_x1){
			x3[i3]= x2[i2];
			i2++;
		}else if (i2>=n_x2){
			x3[i3]= x1[i1];
			i1++;
		}else if (x1[i1]<x2[i2]){
			x3[i3]= x1[i1];
			i1++;
		}else {x3[i3]=x2[i2];
		    i2++;
		}
		i3++;
	}
}
int main(){
	system("color 83");
	NhapMang(a,n1);
	XuatMang(a,n1);
	sxTangDan(a,n1);
	XuatMang(a,n1);
	printf("\n-------------\n");
	NhapMang(b,n2);
	XuatMang(b,n2);
	sxTangDan(b,n2);
	XuatMang(b,n2);
	printf("\n-------------\n");
	tronMang(a,n1,b,n2,c,n3);
	XuatMang(c,n3);
	return 0;
}
