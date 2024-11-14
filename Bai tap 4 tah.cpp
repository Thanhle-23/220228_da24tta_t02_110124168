#include <stdio.h>

int main(){
	int dt, sl, dg, cp;
	
	printf("Nhap so luong hang:\n");
	fflush(stdin);
	scanf("%d",&sl);
	printf("Nhap don gia:\n");
	fflush(stdin);
	scanf("%d",&dg);	
	printf("Nhap chi phi van chuyen:\n");
	fflush(stdin);
	scanf("%d",&cp);
	
	dt=sl*dg-cp;
	
	printf("Doanh thu trong ngay la:%d\n",dt);
	
	return 0;
}
