CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
# CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_pangram.c src/pangram.c src/pangram.h src/bstrlib.h src/utf8util.h src/buniutil.h src/bstraux.h
	@echo Compiling $@
	@cc $(CFLAGS) src/pangram.c src/bstrlib.c src/bstraux.c src/utf8util.c src/buniutil.c test/vendor/unity.c test/test_pangram.c -o tests.out
