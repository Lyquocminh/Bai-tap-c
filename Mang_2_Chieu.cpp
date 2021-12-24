#include <stdio.h>

int m,n;
void nhapMaTran(int x[100][100], int &m, int &n){
	do{
		printf("Nhap so luong dong va cot: ");
		scanf("%d%d", &m,&n);
	}while (m<=0 || n<=0);
	for (int i=0; i<m;i++){
		for (int j=0;j<n;j++){
			printf("a[%d][%d]",i,j );
			scanf("%d", &x[i][j]);
		}
	}
}
void xuatMaTran(int x[100][100], int m, int n){
	printf("phan tu cua ma tran la: \n");
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			printf("\ta[%d][%d]= %d ", i,j, x[i][j]);
		}
		printf("\n");
	}
}
int timKiem(int x[100][100], int m, int n, int gt_can_tim){
	int kq = 0;
	for (int i=0; i<m; i++){
		for (int j=0;j<n; j++){
			if (x[i][j]==gt_can_tim)
			 	kq = 1;
		}
	}
	return kq;
}
void thucHientk(int x[100][100], int m, int n){
	int lua_chon, tim_gt;
	do{
		printf("\nNhap gia tri can tim: ");
		scanf("%d", &tim_gt);
		if (timKiem(x,m,n,tim_gt)== 1)
			printf("\nGia tri can tim co trong ma tran");
		else printf("\nGia tri can tim khong co trong ma tran");
		printf("\n-----------------");
		printf("\nNhap so bat ki khac 0 de tiep tuc (nhap 0 de thoat): ");
		scanf("%d", &lua_chon);
		printf("\n-----------------");
	}while (lua_chon != 0);
}
int main(){
	int a[100][100];
	nhapMaTran(a, m,n);
	xuatMaTran(a,m,n);
	printf("-------------------");
	thucHientk(a,m,n);
	return 0;
}
