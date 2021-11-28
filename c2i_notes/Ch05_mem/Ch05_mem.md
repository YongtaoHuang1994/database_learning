
标准的C程序库提供了四个内存管理的例程：
- malloc
- alloc
- realloc
- free

#### void* malloc (size_t size);
其中size_t代表unsigned int。
malloc: 分配一块size Byte大小的内存，返回一个指向该块内存开始的指针，指针类型是void。

#### void* calloc (size_t num, size_t size);
为一个大小为num的数组分配内存，每个元素的大小是size，把每个元素初始化为0。

#### void* realloc (void* ptr, size_t size);
将ptr所指向的内存空间的大小改为size个字节.
如果新分配的内存比原内存大, 那么原内存的内容保持不变, 增加的空间不进行初始化.
如果新分配的内存比原内存小, 那么新内存保持原内存的内容, 增加的空间不进行初始化.
返回指向新分配空间的指针; 若内存不够,则返回NULL, 原ptr指向的内存区不变.

#### void free (void* ptr);
回收由malloc/calloc/realloc分配的内存空间。


举一个列子：

```C
include<stdio.h>
include<stdlib.h>
int main() {
    int *tmp=(int *)calloc(1,sizeof(int));
    *tmp = 123;
    if(!tmp)
        printf("分配内存错误\n");
    else{
        printf("指针地址：%X\n",(unsigned int)tmp);
        printf("指向内存的内容：%d\n",*tmp);
        printf("释放它\n");
        free(tmp);
        printf("释放后，指针的地址：%X\n",(unsigned int)tmp);
        printf("释放后，指针指向的内存的内容：%d\n",*tmp);
    }
    return 0;
}
```