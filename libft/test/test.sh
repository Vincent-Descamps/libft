#!/bin/sh
#gcc -Wall -Werror -Wextra ./test/test.c ./srcs/*.c -I ./includes/ && ./a.out && rm ./a.out
make 
gcc ./test/test.c -L. -lft && ./a.out && rm ./a.out
norminette ./*.c ./*.h | grep -v ": OK!"
