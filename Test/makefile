EXECS1=main.o
#?= 是如果没有被赋值过就赋予等号后面的值
MYCC?=clang++

all: ${EXECS1} 

main.o:main.cpp
	${MYCC} -o main.o main.cpp -g -Wall -std=c++11

#make clean
clean:
	rm -f ${EXECS1} 
