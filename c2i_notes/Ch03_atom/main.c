#include <stdio.h>
#include <stdlib.h>
#include"list.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char *x = Atom_string("an_atom");
	printf("%d\n", x); 
	int a = Atom_length(x);
	printf("%d\n", a); // 输出7
	printf("==========================\n"); 
	char *y = Atom_int(255); // 换99试试 
	printf("%d\n", y); 
	int b = Atom_length(y);
	printf("%d\n", b); // 255输出3 99输出2
	return 0;
}
