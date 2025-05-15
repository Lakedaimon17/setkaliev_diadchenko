clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

root.o: root.h root.c
	gcc -g -c root.c -o root.o

root.a: root.o
	ar rc root.a root.o

root_test.o: root_test.c
	gcc -g -c root_test.c -o root_test.o

root_test: root_test.o root.a
	gcc -g -static -o root_test root_test.o root.a -lm

test: root_test
	./root_test
