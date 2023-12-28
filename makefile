# Default Lapacke: Openblas at CESGA
LDLIBS=-lopenblas

# Other systems (my Debian boxes, for example)
#LDLIBS=-llapacke

# Intel MKL at CESGA
# Module needed: imkl
# => module load openblas
# LDLIBS for intel compiler: icx (module needed: intel)
# Just invoke make like this: make CC=icx
#LDLIBS=-qmkl=sequential -lmkl_intel_lp64

dgesv: dgesv.o timer.o main.o
	$(CC) $(LDFLAGS) -o dgesv dgesv.o timer.o main.o $(LDLIBS)

dgesv.o: dgesv.c dgesv.h
	$(CC) $(CFLAGS) -c dgesv.c

timer.o: timer.c timer.h
	$(CC) $(CFLAGS) -c timer.c

main.o: main.c dgesv.h timer.h
	$(CC) $(CFLAGS) -c main.c

clean:
	$(RM) dgesv *.o *~

