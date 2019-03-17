# 测试文件夹

将写好的源程序加入main.cpp中并在当前路径下打开终端make

未安装clang的，可以在makefile中更改MYCC?=clang++

若出现 make: 警告：检测到时钟错误。您的创建可能是不完整的。
可使用touch ./* 和touch ../*命令更新文件