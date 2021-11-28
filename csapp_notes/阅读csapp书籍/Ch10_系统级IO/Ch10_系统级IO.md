
### 10.1 Unix IO
Linux中所有IO设备都被模型化成文件。
- 打开文件
- 改变offset
- 读写文件
- 关闭文件

### 10.2 文件
文件主要3种类型：
- 普通文件
- 目录
- socket套接字

### 10.3&4 打开关闭和读写文件

### 10.5 用RIO包健壮的读写
Robust IO
有缓冲 
无缓冲

### 10.6&7 读写文件元数据 & 目录内容

### 10.8 共享文件
内核中有3个数据结构来表示打开的文件
- 描述符表
- 文件表
- V-node
实现进程间的文件共享。

### 10.9 IO重定向
指的是将磁盘文件和标准IO联系起来。

### 10.10 标准IO
C语言libc库
- fopen fclose 开关文件
- fread fwrite 读写字节
- fgets fputs 读写字符串
- scanf printf 复杂格式IO

### 10.11 综合：我该使用那些IO函数？
三种IO函数
- Unix IO：read 
- 标准IO：fread
- RIO：rio_readn

三个准则：
- G1: 尽可能使用标准IO
- G2: 不要使用scanf或者rio_readlined来读二进制文件
- G3: 网络套接字IO使用RIO

