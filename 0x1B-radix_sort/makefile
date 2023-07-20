main ?= 0-main.c 

build:
	@gcc -Wall -Wextra -Werror -pedantic $(main) 0-radix_sort.c print_array.c -o radix_sort
	./radix_sort
	@rm radix_sort
