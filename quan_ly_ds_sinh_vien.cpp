#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
struct Date{
	int day, month, year;
};
struct SinhVien{
	char hoTen[30];
	char GioiTinh[4];
	char hocLuc[11];
	char maLop[10];
	int MSSV, tuoi;
	Date ngaySinh;
	float mon1, mon2, mon3, diemTB;
};
char* lTrim(char s[]){
	int i=0;
	while(s[i]==' ') i++;
	if(i>0) strcpy(&s[0], &s[i]);
	return s;
}
char* rTrim(char s[]){
	int i= strlen(s)-1;
	while(s[i]==' ') i--;
	s[i+1]='\0';
	return s;
}
char* trim(char s[]){
	lTrim(rTrim(s));
	char *ptr= strstr(s,"  ");
	while(ptr!='\0'){
		strcpy(ptr, ptr+1);
		ptr= strstr(s,"  ");
	}
	return s;
}
char* nameStr(char s[]){
	trim(s);
	strlwr(s);
	int l= strlen(s);
	int i=0;
	for(;i<l;i++)
		if(i==0 || s[i-1]==' ') s[i]= toupper(s[i]);
	return s;
}
void ngaySinh(SinhVien &sv){
	printf("Ngay thang nam sinh\n");
	printf("\tNgay: "); scanf("%d", &sv.ngaySinh.day);
	printf("\tThang: "); scanf("%d", &sv.ngaySinh.month);
	printf("\tNam: "); scanf("%d", &sv.ngaySinh.year);
}
void nhapSV(SinhVien &sv){
	fflush(stdin);
	printf("Ho va ten: "); gets(sv.hoTen); nameStr(sv.hoTen);
	printf("MSSV: "); scanf("%d", &sv.MSSV);
	fflush(stdin);
	printf("Ma lop: "); gets(sv.maLop);
	printf("Gioi tinh: "); gets(sv.GioiTinh);
	ngaySinh(sv);
	printf("Diem mon 1: "); scanf("%f", &sv.mon1);  
	printf("Diem mon 2: "); scanf("%f", &sv.mon2);
	printf("Diem mon 3: "); scanf("%f", &sv.mon3);
}
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
		printf("\nNhap vao sinh vien thu %d\n", i+1);
		capNhatSV(ds[i]);
	}
}
void themSinhVien(SinhVien ds[], int &n){
	int m;
	printf("\nNhap so luong sinh vien can them: "); scanf("%d", &m);
	n+=m;
	for(int i=n-m;i<n;i++){
		printf("\nNhap vao sinh vien thu %d\n", i+1);
		capNhatSV(ds[i]);
	}
}
void inSV(SinhVien sv){
	printf("\n%30s %4d %10s %10s %2d/%2d/%4d  %4d  %3.2f   %3.2f   %3.2f   %5.2f %11s", sv.hoTen, sv.MSSV, sv.maLop, sv.GioiTinh, sv.ngaySinh.day,sv.ngaySinh.month,sv.ngaySinh.year, sv.tuoi, sv.mon1, sv.mon2, sv.mon3, sv.diemTB, sv.hocLuc);
}
void inDSSV(SinhVien ds[], int n){
	printf("%30s %4s %10s %10s %10s %4s  %5s  %5s  %5s  %7s %11s", "Ho va ten", "MSSV", "Ma lop", "Gioi tinh", "Ngay sinh", "Tuoi", "Mon 1", "Mon 2", "Mon 3", "Diem TB", "Hoc luc");
	for(int i = 0; i < n; i++)
		inSV(ds[i]);
	printf("\n");
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
	printf("%30s %4s %10s %10s %10s %4s  %5s  %5s  %5s  %7s %11s", "Ho va ten", "MSSV", "Ma lop", "Gioi tinh", "Ngay sinh", "Tuoi", "Mon 1", "Mon 2", "Mon 3", "Diem TB", "Hoc luc");
	for(int i = 0; i < n; i++)
		if(strcmp(ds[i].hocLuc, hl)==0)
			inSV(ds[i]);
	printf("\n");
}
void inDSSV_theoMaLop(SinhVien ds[], int n){
	printf("\nNhap vao ma lop: ");
	char lop[10];
	gets(lop);
	strupr(lop);
	printf("%30s %4s %10s %10s %10s %4s  %5s  %5s  %5s  %7s %11s", "Ho va ten", "MSSV", "Ma lop", "Gioi tinh", "Ngay sinh", "Tuoi", "Mon 1", "Mon 2", "Mon 3", "Diem TB", "Hoc luc");
	for(int i = 0; i < n; i++)
		if(strcmp(ds[i].maLop, lop))
			inSV(ds[i]);
	printf("\n");
}
void TimSVTheoTen(SinhVien ds[], int n, char ten[]){
	printf("%30s %4s %10s %10s %10s %4s  %5s  %5s  %5s  %7s %11s", "Ho va ten", "MSSV", "Ma lop", "Gioi tinh", "Ngay sinh", "Tuoi", "Mon 1", "Mon 2", "Mon 3", "Diem TB", "Hoc luc");
	int kt=0;
	for(int i=0;i<n;i++)
		if(strcmp(ten,ds[i].hoTen)==0){
			inSV(ds[i]);
			kt++;
		}
	if(kt==0)
		printf("\n\tKHONG TIM THAY TEN\n");		
}
int TimSVTheoID(SinhVien ds[], int n, int ID){
	for(int i=0;i<n;i++)
		if(ID==ds[i].MSSV)
			return i;
	return -1;
}
void Xoa(SinhVien ds[], int &n, int i){
	for(int j=i;j<n-1;j++)
				ds[j]=ds[j+1];
			n--;
}
void XoaSV(SinhVien ds[], int &n){
	int ID;
	printf("\nNhap vao ID: "); scanf("%d", &ID);
	int kt= TimSVTheoID(ds,n,ID);
	if(kt==-1)
		printf("\tKHONG TIM THAY");
	else{
		printf("%30s %4s %10s %10s %10s %4s  %5s  %5s  %5s  %7s %11s", "Ho va ten", "MSSV", "Ma lop", "Gioi tinh", "Ngay sinh", "Tuoi", "Mon 1", "Mon 2", "Mon 3", "Diem TB", "Hoc luc");	
		inSV(ds[kt]);
		char x;
		printf("\nXac nhan xoa? [y/n]: "); scanf("%c", &x);
		if(x=='y'){
			Xoa(ds,n,kt);
			printf("Da xoa");
		}
	}
}
void swap(SinhVien &a,SinhVien &b){
	SinhVien temp = a;
	a= b;
	b= temp;
}
void SapXepTheoDTB(SinhVien ds[], int n){
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(ds[i].diemTB<ds[j].diemTB)
				swap(ds[i],ds[j]);
}
void SapXepTheoTen(SinhVien ds[], int n){
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(strcmp(ds[i].hoTen, ds[j].hoTen)<0)
				swap(ds[i], ds[j]);
}
void NhapTuFile(SinhVien ds[], int &n){
	char tenFile[30];
	printf("\nNhap vao duong dan ten File: ");
	fflush(stdin); gets(tenFile);
	
	FILE *f;
	f= fopen(tenFile,"rb");
	if(f==NULL){
		printf("\nLoi tao hoac mo file");
		return;
	}
	fread(&n, sizeof(n),1,f);
	for(int i=0; i<n; i++)
		fread(&ds[i], sizeof(SinhVien), 1, f);
	fclose(f);
}
void XuatVaoFile(SinhVien ds[], int n){
	char tenFile[30];
	printf("\nNhap vao duong dan ten File: ");
	fflush(stdin); gets(tenFile);
	
	FILE *f;
	f= fopen(tenFile,"wb");
	if(f==NULL){
		printf("\nLoi tao hoac mo file");
		return;
	}
	fwrite(&n, sizeof(n),1,f);
	for(int i=0; i<n; i++)
		fwrite(&ds[i], sizeof(SinhVien), 1, f);
	fclose(f);
}
void suaThongTinSV(SinhVien ds[], int n){
	int ID;
	printf("\nNhap vao ID: "); scanf("%d", &ID);
	int kt= TimSVTheoID(ds,n,ID);
	if(kt==-1)
		printf("\tKHONG TIM THAY");
	else{
		printf("%30s %4s %10s %10s %10s %4s  %5s  %5s  %5s  %7s %11s", "Ho va ten", "MSSV", "Ma lop", "Gioi tinh", "Ngay sinh", "Tuoi", "Mon 1", "Mon 2", "Mon 3", "Diem TB", "Hoc luc");
		inSV(ds[kt]);
		printf("\n");
		capNhatSV(ds[kt]);
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
		printf("\n7-Tim sinh vien theo ten");
		printf("\n8-Xoa sinh vien theo ID");
		printf("\n9-Sap xep danh sach sinh vien theo DTB");
		printf("\n10-Sap xep danh sach sinh vien theo ten");
		printf("\n11-Them sinh vien");
		printf("\n12-Sua thong tin sinh vien");
		printf("\n13-Nhap danh sach sinh vien tu File");
		printf("\n14-Xuat danh sach sinh vien vao File");
		printf("\n15-Xoa man hinh");
		printf("\n0-Thoat khoi chuong trinh");
		printf("\nNhap vao lua chon: ");
		scanf("%d", &a);
		fflush(stdin);
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
			case 7:
				char ten[30];
				fflush(stdin);
				printf("\nNhap vao ten muon tim: "); gets(ten);
				TimSVTheoTen(ds,n,ten);
				break;
			case 8:
				XoaSV(ds,n);
				break;
			case 9:
				SapXepTheoDTB(ds,n);
				inDSSV(ds,n);
				break;
			case 10: 
				SapXepTheoTen(ds,n);
				inDSSV(ds,n);
				break;
			case 11:
				themSinhVien(ds,n);
				break;
			case 12:
				suaThongTinSV(ds,n);
				break;
			case 13:
				NhapTuFile(ds,n);
				break;
			case 14:
				XuatVaoFile(ds,n);
				break;
			case 15:
				system("cls");
				break;
			case 0:
				printf("\nThoat khoi chuong trinh");
				break;
			default:
				printf("\nKhong hop le");
		}
		printf("\nNhan phim bat ky de tiep tuc");
		getch();
	}while(a!=0);
	return 0;
}
