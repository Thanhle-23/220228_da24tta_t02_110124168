#include <stdio.h>

int main(){
	
	int dl = 50, db= 23, c=30;
	float s1,s2,s3;
	float cv=12.56;
	const float PI = 3.1415;
	
	s1=((dl+db)*c)/2;
	s2=(cv*cv)/(4*PI);
	s3=s1-s2;
	
	printf("Dien tich con lai cua san truong la: %.2f\n", s3);
	
	return 0;
	
}
