CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_raindrops.c src/raindrops.c src/raindrops.h src/bstrlib.h src/bstraux.h
	@echo Compiling $@
	@cc $(CFLAGS) src/raindrops.c src/bstrlib.c src/bstraux.c test/vendor/unity.c test/test_raindrops.c -o tests.out
