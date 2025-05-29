clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

linked_list.o: linked_list.h linked_list.c
	gcc -g -c linked_list.c -o linked_list.o

linked_list.a: linked_list.o
	ar rc linked_list.a linked_list.o

linked_list_test.o: linked_list_test.c
	gcc -g -c linked_list_test.c -o linked_list_test.o

linked_list_test: linked_list_test.o linked_list.a
	gcc -g -static -o linked_list_test linked_list_test.o linked_list.a -lm

test: linked_list_test
	./linked_list_test