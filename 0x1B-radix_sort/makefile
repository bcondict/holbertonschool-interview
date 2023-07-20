main ?= 0-main.c 

radix1:
	@gcc -Wall -Wextra -Werror -pedantic $(main) 0-radix_sort.c print_array.c -o radix_sort
	./radix_sort
	@rm radix_sort

radix2:
	@gcc -Wall -Wextra -Werror -pedantic $(main) 1-radix_sort.c print_array.c -o radix_sort
	./radix_sort
	@rm radix_sort
