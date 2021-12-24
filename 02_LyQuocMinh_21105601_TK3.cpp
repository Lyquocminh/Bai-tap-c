#include <stdio.h>
#include <math.h>

// cau a

void NhapToaDoCacSieuThi(float x[], float y[], float &a, float &b){
	printf("Nhap toa do ban dang dung\n");
	printf("Hoanh do: ");
	scanf("%f", &a);
	printf("Tung do: ");
	scanf("%f", &b);
	for(int i = 0; i < 5; i++){
		printf("\nNhap hoanh do sieu thi thu %d: ", i);
		scanf("%f", &x[i]);
		printf("Nhap tung do sieu thi thu %d: ", i);
		scanf("%f", &y[i]);
	}
}
// cau b
float KhoangCach(float x, float y, float a, float b){
	return sqrt(pow(a-x,2.0) + pow(b-y,2));
}
int TimSieuThiGanNhat(float x[], float y[], float a, float b){
	int min = 0;
	for(int i = 1; i < 5; i++)
		if(KhoangCach(x[i], y[i], a, b) < KhoangCach(x[min], y[min], a,b))
			min = i;
	return min;
}
void XuatKetQua(float x[], float y[], int min){
	printf("\nSieu thi gan nhat la %d", min);
	printf("\nToa do la x = %.2f, y = %.2f", x[min], y[min]);
}
// cau c
void NhapSoXang(float &litXangConLai, float &litXangTieuTonTrong1km){
	printf("\nSo nhien lieu con lai trong xe la: ");
	scanf("%f", &litXangConLai);
	printf("\nSo lit xang tieu ton trong 1 km la: ");
	scanf("%f",&litXangTieuTonTrong1km);
}
void CacSieuThiDuXangDiDen(float a, float b, float litXangConLai, float litXangTieuTonTrong1km, float x[], float y[]){
	float soKmCoTheDiDuoc = litXangConLai/litXangTieuTonTrong1km;
	printf("\nCac sieu thi ma xe du xang di toi la: ");
	for(int i = 0; i < 5; i++)
		if( KhoangCach(x[i], y[i], a, b) <= soKmCoTheDiDuoc){
			printf("\nSieu thi thu %d", i);
			printf("\nToa do: x = %.2f, y = %.2f", x[i], y[i]);
			printf("\nKhoang cach chay la %.2f", KhoangCach(x[i], y[i], a, b));
			printf("\nSo xang tieu ton la: %.2f", KhoangCach(x[i], y[i], a, b)*litXangTieuTonTrong1km);
			printf("\nSo xang thua %.2f", litXangConLai - KhoangCach(x[i], y[i], a, b)*litXangTieuTonTrong1km);
		}
}
// cau d
void PhiDauXe(float t[]){
	for(int i = 0; i < 5; i++){
		printf("\nChi phi dau xe sieu thi thu %d = ", i);
		scanf("%f", &t[i]);
	}
}
void CacSieuThiGanNhat(float a, float b, float x[], float y[], int sieuThiKhoangCachMin[], int min, int &dem){
	for(int i = 0; i < 5; i++)
		if(KhoangCach(x[i], y[i], a, b) == KhoangCach(x[min], y[min], a, b))
			sieuThiKhoangCachMin[dem++] = i;
}

int SieuThiGanVaPhiRe(int sieuThiGan[], int dem, float t[]){
	int t_min = sieuThiGan[0];
	for(int i = 0; i < dem; i++)
		if(t[sieuThiGan[i]] < t[t_min])
			t_min = sieuThiGan[i];
	return t_min;
}
void XuatSieuThiGanVaRe(int t_min, float x[], float y[], float t[], int dem, int sieuThiGan[]){
	printf("\nTrong cac sieu thi co khoang cach min, sieu thi gan nhat la");
	for(int i = 0; i < dem; i++)
		if(t[sieuThiGan[i]] == t[t_min]){
			printf("\nSieu thi thu %d", sieuThiGan[i]);
			printf("\nToa do x = %.2f, y = %.2f", x[sieuThiGan[i]], y[sieuThiGan[i]]);
			printf("\nChi phi la %.2f", t[t_min]);
		}
	
}
int main(){
	float x[5], y[5], a, b;
//cau a
	NhapToaDoCacSieuThi(x, y, a, b);
//cau b
	int min = TimSieuThiGanNhat(x, y, a, b);
	XuatKetQua(x, y, min);
//cau c
	float litXangConLai;
	float litXangTieuTonTrong1km;
	NhapSoXang(litXangConLai, litXangTieuTonTrong1km);
	CacSieuThiDuXangDiDen(a, b, litXangConLai, litXangTieuTonTrong1km, x, y);
//cau d	
	float t[5];
	PhiDauXe(t);
	int dem = 0, sieuThiGan[dem];
	CacSieuThiGanNhat(a, b, x, y, sieuThiGan, min, dem);
	int t_min = SieuThiGanVaPhiRe(sieuThiGan, dem, t);
	XuatSieuThiGanVaRe(t_min, x, y, t, dem, sieuThiGan);
	return 0;
}
