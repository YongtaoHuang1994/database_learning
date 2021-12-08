
### 一、加法
程序名main_add.c
```C
#include<stdio.h>
int main(){
    long a = 1;
    long b = 2;
    long c = a + b;
    printf("%ld\n", c);
    return 0;
}
```

```
// 编译生成.s后缀的汇编文件
$ gcc -S main_add.c
// 如果想把C语言变量的名称作为汇编语言语句中的注释，可以加上-fverbose-asm选项：
$ gcc -S -fverbose-asm main_add.c
// 生成可执行文件
$ gcc -Og -o main_add main_add.c
// 执行可执行文件
$ ./main_add
// 查看可执行文件
$ objdump -d main_add
```

编译成汇编后完整的代码，我们只关注核心部分：
```ass
movq	$1, -24(%rbp)       // long a = 1;
movq	$2, -16(%rbp)       // long b = 2;
movq	-24(%rbp), %rdx     
movq	-16(%rbp), %rax
addq	%rdx, %rax          // long c = a + b;
```
<div STYLE="page-break-after: always;"></div>

### 二、右移
程序名main_lefts.c
```C
#include<stdio.h>
int main(){
    long a = 8;
    long b = a >> 3;
    printf("%ld\n", b);
    return 0;
}
```
```ass
movq	$8, -16(%rbp)       // long a = 8;       
movq	-16(%rbp), %rax     
sarq	$3, %rax            // long b = a >> 3; 右移3位 P129 图3-10
movq	%rax, -8(%rbp)
```

### 三、if判断
程序名main_if.c
```C
#include<stdio.h>
int main(){
	long a = 4;
	long b = 2;
	long c;
	if (a>b) {
		c = 1;
	} else {
		c = 0;
	}
	printf("%ld\n", c);
}
```
```ass
	movq	$4, -16(%rbp)       // long a = 4;
	movq	$2, -8(%rbp)        // long b = 2;
	movq	-16(%rbp), %rax
	cmpq	-8(%rbp), %rax
	jle	.L2
	movq	$1, -24(%rbp)       // c = 1;
	jmp	.L3
.L2:
	movq	$0, -24(%rbp)       // c = 0;
```
<div STYLE="page-break-after: always;"></div>

### 四、switch判断
```C
#include <stdio.h>
int main(){
    int a = 1;
    switch(a){
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        default:printf("error\n"); break;
    }
    return 0;
}
```
```ass
	movl	$1, -4(%rbp)        // int a = 4;
	cmpl	$1, -4(%rbp)        // switch(a)
	je	.L2
	cmpl	$2, -4(%rbp)
	je	.L3
	jmp	.L7
.L2:
	leaq	.LC0(%rip), %rdi    // case 1:
	call	puts@PLT
	jmp	.L5                     // L5 return 0;
```
<div STYLE="page-break-after: always;"></div>

### 五、for循环
```C
#include <stdio.h>
int main(){
    int i;
    for(i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }
    return 0;
}
```
```ass
	movl	$1, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)        // i++  for(i = 1; i <= 10; i++) {
.L2:
	cmpl	$10, -4(%rbp)       // i<=10  for(i = 1; i <= 10; i++) {
	jle	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
```
<div STYLE="page-break-after: always;"></div>

### 六、数组
```C
#include <stdio.h>
int main(){
	int a[5] = {1,2,3,4,5};
	printf("%d\n", a[2]);
}
```

```ass
movl	$1, -32(%rbp)       // int a[5] = {1,2,3,4,5};
movl	$2, -28(%rbp)
movl	$3, -24(%rbp)
movl	$4, -20(%rbp)
movl	$5, -16(%rbp)
movl	-24(%rbp), %eax     // printf("%d\n", a[2]);
movl	%eax, %esi
leaq	.LC0(%rip), %rdi
movl	$0, %eax
call	printf@PLT          // printf("%d\n", a[2]);
movl	$0, %eax
```