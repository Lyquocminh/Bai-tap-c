#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	printf("Nhap vao so luong ptu: ");
	scanf("%d", &n);
	
	int* pt = (int*)calloc(n,sizeof(int));
	if (pt ==NULL){
		printf("\nError: Khong cap nhat duoc vung nho");
		return 0;
	}
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", pt+i);
	}
		
	for(int i=0; i<n; i++)
		printf("\t%d", *(pt+i));
		
	free(pt);
	return 0;
}
