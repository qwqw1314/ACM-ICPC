#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define pi 3.14159265358979

int r;
double r2;
double r3;

int main()
{
	scanf("%d", &r);
	r2 = r * r * pi;
	r3 = r * r * 2;
	printf("%.6lf\n%.6lf", r2, r3);
	return 0;
}