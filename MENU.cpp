#include <stdio.h>
#include <conio.h>

int soNgayCuaThang(int thang, int nam) {
    switch (thang){
    	case 1:
    	case 3:
    	case 5:
    	case 7:
    	case 8:
    	case 10:
    	case 12:
    		return 31;
    	case 4:
    	case 6:
    	case 9:
    	case 11:
    		return 30;
    	case 2: 
    	    return ((nam%400==0)||(nam%4==0&&nam%100!=0))?29:28;
    	default:
    		return -1;
	}
}

int ngayTrongNam(int ngay, int thang, int nam){
	int ntn = 0;
	for (int i =1; i<thang; i++){
		ntn+=soNgayCuaThang(i,nam);
	}
	ntn+= ngay;
	return ntn;
}
void timNgayTruocDo(int ngay, int thang, int nam) {
	if (ngay==1){
		if (thang==1){
			ngay=31;
			thang=12;
			nam--;
		}else{ thang--;
		       ngay =soNgayCuaThang(thang,nam);      
		}		
	}else ngay--;
	printf("\n Ngay truoc do: %d/%d/%d\n", ngay, thang, nam);
}
void timNgayKeTiep(int ngay,int thang, int nam){
	int nct = soNgayCuaThang(thang, nam);
	if (ngay ==nct){
		if (thang==12){
			ngay =1; thang=1; nam++;
		}else { ngay=1; thang++;
		}
	}else ngay++;
	printf("\n Ngay ke tiep %d/%d/%d\n", ngay, thang, nam);
}
int main(){
	int ngay,thang,nam;
	char c;
	do {
	    printf("\nMENU\n");
	    printf("1- Nhap vao ngay thang nam\n");
	    printf("2- Tim so ngay trong nam (Tinh den ngay ban nhap)\n");
	    printf("3- Tim so ngay cua thang\n");
	    printf("4- Tim ngay truoc do\n");
	    printf("5- Tim ngay ke tiep\n");
	    printf("0- Thoat\n");
	    printf("Lua chon cua ban: ");
	    scanf("%c", &c);
	    if (c=='1') {
	    	do{
	        	printf("Nhap vao ngay thang nam: ");
	        	scanf("%d%d%d", &ngay,&thang,&nam);
	        }while (ngay>31||ngay<1||thang<1||thang>12||nam<1);
		}
	    else if (c=='2') printf("\n So ngay trong nam: %d\n", ngayTrongNam(ngay,thang,nam));
        else if (c=='3') printf("\n So ngay cua thang (tinh den ngay ban nhap) %d\n", soNgayCuaThang(thang,nam));
        else if (c=='4') timNgayTruocDo(ngay,thang,nam);
        else if (c=='5') timNgayKeTiep(ngay,thang,nam);
 	}while(c!='0');	
 	return 0;
}
	
