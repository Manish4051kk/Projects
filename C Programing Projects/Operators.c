//header file
#include<stdio.h>

int main()
{
	int x=4, y =3;
	int sum, sub, mul, mod;
	sum = x + y;
	printf("%d\n",sum);
	sub = x - y;
	printf("%d\n",sub);
	mul = x * y;
	printf("%d\n",mul);
	float div = (float)x / y;
	printf("%f\n",div);
	mod = x % y;
	printf("%d\n",mod);
	
	int result1 = 5 + 3 * 2;
	printf("r1 %d\n",result1);
	
	int result2 = 10 > 5;
	printf("r2 %d\n",result2);
	
	int result3 = !(4 == 4) && (3 < 5);
	printf("r3 %d\n",result3);
	
	int result4 = 7;	 
    result4 += 3;
	printf("r4 %d\n",result4);

	int result5 = 5;	 
    result5++;
	printf("r5 %d\n",result5);
	
	int result6 = 3 + 4 * 2 / (1 - 5);
	printf("r6 %d\n",result6);
	
	return 0;

}