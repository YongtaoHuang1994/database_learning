
#### 源码安装
```
$ apt install -y zlib1g-dev libreadline-dev
$ wget https://ftp.postgresql.org/pub/source/v11.5/postgresql-11.5.tar.gz
$ tar -zxvf postgresql-11.5.tar.gz
$  ./configure  --enable-debug --enable-depend --enable-cassert --prefix=/home/gpadmin/pg115
$ make -j4 & make install
```

$ vim /home/gpadmin/.bashrc
$ vim /etc/profile
```
export PG_HOME=/home/gpadmin/pg115
export PATH=$PG_HOME/bin:$PATH
LD_LIBRARY_PATH=/home/gpadmin/pg115/lib
export LD_LIBRARY_PATH
```

```
$ source /ect/profile
$ source  /home/gpadmin/.bashrc
$ psql --version
```
![avatar](安装pgsql-1.png)

如果用apt安装，会自动生成一个postgres用户。如果用源码安装，那么需要自行设定。
```
$ adduser postgres
$ su - postgres
$ chown -R postgres:postgres /home/gpadmin/pg115/data
$ chown -R postgres:postgres /home/gpadmin/pg115/logs
$ chmod -R 775 /home/gpadmin/pg115/*
```
![avatar](安装成功.png)
```
$ /home/gpadmin/pg115/bin/initdb -D /home/gpadmin/pg115/data/
$ /home/gpadmin/pg115/bin/pg_ctl -D /home/gpadmin/pg115/data/ -m fast start
```

![avatar](安装成功后的data目录.png)
![avatar](启动服务.png)

以下用一个简单的办法进入数据库：
```
$ psql template1
$ create user gpadmin with password '123456';
$ create database gpadmin owner gpadmin;
$ grant all privileges on database gpadmin to gpadmin;
$ \q
# 此后随时都可以进入
$ psql
```

![avatar](确认本机运行几个postgre实例.png)

#### 如何gdb调试

![avatar](gdb调试select1.png)