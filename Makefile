ifneq ($(findstring .exe, $(SHELL)), )
    CC     = tcc
endif
CFLAGS = -Wall -Werror

test.exe: w1ce.o test.o
	$(CC) -o $@ $+

test.o: test.c w1ce.h
	$(CC) $(CFLAGS) -c $<

w1ce.o: w1ce.c w1ce.h
	$(CC) $(CFLAGS) -c $<

