#include <stdio.h>
#include <string.h>
#include <conio.h>
int main(){
	char c[50],s[50];
	printf("Nhap vao chuoi thu nhat: ");
	scanf("%s", &c);
	getchar();
	fflush(stdin);
	printf("\nNhap vao chuoi thu hai");
	fgets(s, 50, stdin);
	printf("\nChuoi thu nhat: %s", c);
	printf("\nChuoi thu hai: %s", s);
}
