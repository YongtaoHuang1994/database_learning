#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	List_T p1, p2;
	p1 = List_list(NULL);
	p2 = List_list("Atom", "Mem", "Arena", "List", NULL);
	int a = List_length(p1);
	printf("%d\n", a);
	int b = List_length(p2);
	printf("%d\n", b);
	return 0;
}
