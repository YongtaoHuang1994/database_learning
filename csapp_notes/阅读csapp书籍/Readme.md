#### CSAPP按照以下章节顺序阅读
第一、二、三章：基础理论。
第八、十、十一、十二章：进程。
第六、九章：存储。
计划先粗读一遍，再精读（做实验）一遍。


#### csapp.h的使用

1、把csapp.h csapp.c文件放到/usr/include
2、在csapp.h里面最后一行#end if之前添加：#include <csapp.c>
3、gcc -o fork fork.c -lpthread  && ./fork