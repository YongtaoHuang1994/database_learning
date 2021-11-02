### 一、C语言基础

#### （1）字符、字符指针、字符数组
字符、字符指针：
```c
#include <stdio.h>
int main (){
	char var = "a";   /* 实际变量的声明 */
	char *ip;        /* 指针变量的声明 */
	ip = &var;  /* 在指针变量中存储 var 的地址 */
	printf("var 变量的地址: %p\n", &var  );
	/* 在指针变量中存储的地址 */
	printf("ip 变量存储的地址: %p\n", ip );
	/* 使用指针访问值 */
	printf("*ip 变量的值: %d\n", *ip );
	return 0;	
}
```
字符数组：
```c
int main(int argc, char *argv[]) {	
	char *names[] = {"Zara", "Hina", "Nuha", "Sara"};
	int i = 0;
	for ( i = 0; i < 4; i++) {
	  printf("Value of names[%d] = %s\n", i, names[i] );
	}
	return 0;
}
```
#### （2）结构体
```c
#include <stdio.h>
struct student{
	char name[50];
	int roll;
	float marks;
} s; // s是student的缩写
int main() {
	printf("输入信息:\n");
	printf("名字: ");
	scanf("%s", s.name);
	printf("编号: ");
	scanf("%d", &s.roll);
	printf("成绩: ");
	scanf("%f", &s.marks);
	printf("显示信息:\n");
	printf("名字: ");
	puts(s.name);
	printf("编号: %d\n",s.roll);
	printf("成绩: %.1f\n", s.marks);
	return 0;
}
```
#### （3）const和static关键字
程序的局部变量存在于（堆栈）中，全局变量存在于（静态区）中，动态申请数据存在于（堆）中。

static声明局部变量和局部函数，只在本文件内使用，无法被外部引用。这个和extern对立。

const声明常量，主要分三种情况
（1）const int MAX = 255;
（2）void fun(const int x){} 此时，x在该函数中运算值始终不能变。
（3）const fun(int x), 返回const，限定返回值无法别修改。

### 附录
例程

```C
#include <stdio.h>
#include <stdlib.h>
#include"atom.h"

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
```


完整注释
```C

#define NELEMS(x) ((sizeof (x))/(sizeof ((x)[0])))

static struct atom {
	struct atom *link;
	int len;
	char *str;
} *buckets[2048];

static unsigned long scatter[] = { //事实上这里256个数
2078917053, 1602280572
};

const char *Atom_string(const char *str) {
	assert(str);
	return Atom_new(str, strlen(str));
}
/*

*/
const char *Atom_int(long n) {
	char str[43];
	char *s = str + sizeof str;
	unsigned long m;
	if (n == LONG_MIN)
		m = LONG_MAX + 1UL;
	else if (n < 0)
		m = -n;
	else
		m = n;
	do
		*--s = m%10 + '0';
	while ((m /= 10) > 0);
	if (n < 0)
		*--s = '-';
	return Atom_new(s, (str + sizeof str) - s);
}
/*
**params: **
*str: 指向字节序列的指针
len: 该序列中的字节数目
*/

const char *Atom_new(const char *str, int len) {
	unsigned long h;
	int i;
	struct atom *p;
	assert(str);
	assert(len >= 0);
	for (h = 0, i = 0; i < len; i++)
		h = (h<<1) + scatter[(unsigned char)str[i]];
	h &= NELEMS(buckets)-1;
	for (p = buckets[h]; p; p = p->link)
		if (len == p->len) {
			for (i = 0; i < len && p->str[i] == str[i]; )
				i++;
			if (i == len)
				return p->str;
		}
	p = ALLOC(sizeof (*p) + len + 1);
	p->len = len;
	p->str = (char *)(p + 1);
	if (len > 0)
		memcpy(p->str, str, len);
	p->str[len] = '\0';
	p->link = buckets[h];
	buckets[h] = p;
	return p->str;
}

int Atom_length(const char *str) {
	struct atom *p;
	int i;
	assert(str);
	for (i = 0; i < NELEMS(buckets); i++)
		for (p = buckets[i]; p; p = p->link)
			if (p->str == str)
				return p->len;
	assert(0);
	return 0;
}
```