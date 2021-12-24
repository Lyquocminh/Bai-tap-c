#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	f = fopen("Doc_ghi_file.txt", "w");
	if(f == NULL){
		printf("\n Loi tao hoac mo file");
		exit(1);
	}
	int n;
	printf("\nNhap vao so n: "); scanf("%d", &n);
	fprintf(f, "%d", n);
	fclose(f);
	f = fopen("Doc_ghi_file.txt", "r");
	fscanf(f, "%d", &n);
	printf("\nGia tri cua n: %d", n);
	fclose(f);
	return 0;
}
