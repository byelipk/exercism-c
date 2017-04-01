CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
# CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_bob.c src/bob.c src/bob.h src/bstrlib.h src/bstraux.h
	@echo Compiling $@
	@cc $(CFLAGS) src/bob.c src/bstrlib.c src/bstraux.c test/vendor/unity.c test/test_bob.c -o tests.out
