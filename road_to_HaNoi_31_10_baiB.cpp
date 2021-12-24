#include <stdio.h>
#include <math.h>
int main(){
	long long x,y,n;
	scanf("%d%d%d", &x,&y,&n);
	long long f[n];
	f[0] = x;
	f[1] = y;
	for (long long i = 2; i < n; i++)
		f[i] = f[i-1] - f[i-2]; 
	int m = pow(10,9)+7;
	if (f[n-1] < 0)
		printf("%d", (f[n-1]+m)%m);
	else 
		printf("%d", f[n-1]%m);
	return 0;
}
