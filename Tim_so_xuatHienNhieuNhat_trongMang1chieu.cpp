#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	do {
		printf("Nhap vao so luong phan tu (0<n<=100): ");
		scanf("%d", &n);
	}while (n<=0||n>100);
	int a[n];
	for (int i = 0; i< n;i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	int x =0,ptu[20], dem[20];
	ptu[x] = a[0]; dem[x] = 1;
	for (int i = 1; i<n; i++){
		if (a[i] != ptu[x]){
			ptu[++x] = a[i];
			dem[x] = 0;
		}
	}
	for (int i = 0; i <x; i++){
		for (int j = 1; j < n; j++ ){
			if (a[j] == ptu[i]) dem[i]++;
		}
	}
	int max = dem[0], xhnn = ptu[0];
	for (int i = 1; i < x; i++){
		if (max < dem[i]) xhnn = ptu[i];
	}
	printf("So xuat hien nhieu nhat trong mang a la: %d", xhnn);
	return 0;
}
