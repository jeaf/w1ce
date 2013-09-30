TCC      = $(USERPROFILE)\app\tcc\tcc.exe
TCC_OPTS = -Wall -Werror

test.exe: w1ce.o test.o
	$(TCC) -o $@ $+

test.o: test.c w1ce.h
	$(TCC) $(TCC_OPTS) -c $<

w1ce.o: w1ce.c w1ce.h
	$(TCC) $(TCC_OPTS) -c $<

