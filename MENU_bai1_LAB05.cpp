#include <stdio.h>
#include <conio.h>
int main() {
	char c;
	do{
		printf("\nNhap vao diem (Nhap X de thoat): ");
		scanf("%s", &c);
		switch(c){
			case ('E'):
				printf("Excellent");
				break;
			case ('V'):
				printf("Very Good");
				break;
			case ('G'):
				printf("Good");
				break;
			case ('A'):
				printf("Average");
				break;
			case ('F'):
				printf("Fall");
				break;
			case ('X'):
				printf("Dung chuong trinh");
				break;
			default:
				printf("Khong hop le");
		}
	}while (c!= 'X');
	return 0;
}
