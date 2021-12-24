#include <stdio.h>
#include <string.h>
#include <time.h>

struct Date{
	int day;
	int month;
	int year;
};
struct SinhVien{
	char hoTen[50];
	int MSSV;
	char GioiTinh[3];
	Date ngaySinh;
	int tuoi;
	float mon1;
	float mon2;
	float mon3;
	float diemTB;
	char hocLuc[20];
	char maLop[10];
};
void xetHocLuc(SinhVien *sv){
	if(sv->diemTB >= 8)
		strcpy(sv->hocLuc,"GIOI");
	else if(sv->diemTB >= 6.5)
		strcpy(sv->hocLuc,"KHA");
	else if(sv->diemTB >= 5)
		strcpy(sv->hocLuc,"TRUNG BINH");
	else if(sv->diemTB >= 3)
		strcpy(sv->hocLuc,"YEU");
	else 
		strcpy(sv->hocLuc,"KEM");
}
void tinhTuoi(SinhVien &sv){
	time_t TTIME = time(0);
	tm* NOW = localtime(&TTIME);
	int namHienTai = NOW->tm_year+1900;
	sv.tuoi = namHienTai - sv.ngaySinh.year;
}
void tinhDiemTB(SinhVien *sv){
	sv->diemTB = (sv->mon1+sv->mon2+sv->mon3)/3;
}
void nhapSV(SinhVien &sv){
	fflush(stdin);
	printf("Ho va ten: "); gets(sv.hoTen);
	printf("MSSV: "); scanf("%d", &sv.MSSV);
	fflush(stdin);
	printf("Ma lop: "); gets(sv.maLop);
	printf("Gioi tinh: "); gets(sv.GioiTinh);
	printf("Ngay thang nam sinh: ");
	scanf("%d%d%d", &sv.ngaySinh.day, &sv.ngaySinh.month, &sv.ngaySinh.year); 
	printf("Diem mon 1: "); scanf("%f", &sv.mon1);  
	printf("Diem mon 2: "); scanf("%f", &sv.mon2);
	printf("Diem mon 3: "); scanf("%f", &sv.mon3);
}
void inSV(SinhVien sv){
	printf("%s\t %d\t %s\t %s\t\t %d/%d/%d\t %d\t %.2f\t\t %.2f\t\t %.2f\t\t %.2f\t\t\t %s\n", sv.hoTen, sv.MSSV, sv.maLop, sv.GioiTinh, sv.ngaySinh.day,sv.ngaySinh.month,sv.ngaySinh.year, sv.tuoi, sv.mon1, sv.mon2, sv.mon3, sv.diemTB, sv.hocLuc);
}
void capNhatSV(SinhVien &sv){
	nhapSV(sv);
	tinhTuoi(sv);
	tinhDiemTB(&sv);
	xetHocLuc(&sv);
}
void nhapDSSV(SinhVien ds[], int &n){
	do{
		printf("\nNhap vao so luong sinh vien: ");
		scanf("%d", &n);
	}while(n<=0);
	for(int i = 0; i < n; i++){
		printf("Nhap vao sinh vien thu %d\n", i+1);
		capNhatSV(ds[i]);
	}
}
void inDSSV(SinhVien ds[], int n){
	printf("Ho va ten\t MSSV\t\t Ma lop\t\t Gioi tinh\t Ngay sinh\t Tuoi\t Diem mon 1\t Diem mon 2\t Diem mon 3\t Diem Trung binh\t Hoc luc");
	for(int i = 0; i < n; i++)
		inSV(ds[i]);
}
void max_DTB(SinhVien ds[], int n){
	int max = 0;
	for(int i = 0; i < n; i++)
		if(ds[max].diemTB < ds[i].diemTB)
			max = i;
	printf("\nSinh vien co diem trung binh cao nhat la: %s", ds[max].hoTen);
	printf("\nVoi so diem la: %.2f", ds[max].diemTB);
}
void min_tuoi(SinhVien ds[], int n){
	int min = 0;
	for(int i = 0; i < n; i++)
		if(ds[min].tuoi > ds[i].tuoi)
			min = i;
	printf("\nSinh vien co tuoi nho nhat la: %s", ds[min].hoTen);
	printf("\nSo tuoi la: %d", ds[min].tuoi);
}
void inDSSV_theoHocLuc(SinhVien ds[], int n){
	printf("\nNhap vao hoc luc: ");
	char hl[10];
	gets(hl);
	strupr(hl);
	printf("Ho va ten\t MSSV\t\t Ma lop\t\t Gioi tinh\t Ngay sinh\t Tuoi\t Diem mon 1\t Diem mon 2\t Diem mon 3\t Diem Trung binh\t Hoc luc\t");
	for(int i = 0; i < n; i++){
		if(strcmp(ds[i].hocLuc, hl)){
			inSV(ds[i]);
			printf("\n");
		}
	}
}
void inDSSV_theoMaLop(SinhVien ds[], int n){
	printf("\nNhap vao ma lop: ");
	char lop[10];
	gets(lop);
	strupr(lop);
	printf("Ho va ten\t MSSV\t\t Ma lop\t\t Gioi tinh\t Ngay sinh\t Tuoi\t Diem mon 1\t Diem mon 2\t Diem mon 3\t Diem Trung binh\t Hoc luc\t");
	for(int i = 0; i < n; i++){
		if(strcmp(ds[i].maLop, lop)){
			inSV(ds[i]);
			printf("\n");
		}
	}
}
int main(){
	SinhVien ds[100];
	int n,a;
	do{
		printf("\n============MENU===========");
		printf("\n1-Nhap danh sach sinh vien");
		printf("\n2-In danh sach sinh vien");
		printf("\n3-Tim sinh vien co diem trung binh cao nhat");
		printf("\n4-Tim sinh vien co so tuoi nho nhat");
		printf("\n5-In danh sach sinh vien theo hoc luc");
		printf("\n6-In danh sach sinh vien theo lop");
		printf("\n0-Thoat khoi chuong trinh");
		printf("\nNhap vao lua chon: ");
		scanf("%d", &a);
		switch(a){
			case 1:
				nhapDSSV(ds,n);
				break;
			case 2:
				inDSSV(ds,n);
				break;
			case 3:
				max_DTB(ds,n);
				break;
			case 4:
				min_tuoi(ds,n);
				break;
			case 5:
				inDSSV_theoHocLuc(ds,n);
				break;
			case 6:
				inDSSV_theoMaLop(ds,n);
				break;
			case 0:
				printf("\nThoat khoi chuong trinh");
				break;
			default:
				printf("\nKhong hop le");
		}
	}while(a!=0);
	return 0;
}
