#include <stdio.h>
#include <stdlib.h>
//#include"arith.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a = 13;
	int b = 5;
	int c;
	c = Arith_ceiling(a, b);
	printf("%d\n", c);
	c = Arith_floor(a, b);
	printf("%d\n", c);
	return 0;
}
