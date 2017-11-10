all:  prelim

prelim:  prelim.c
	gcc -o prelim prelim.c -m32

ret2libc:  ret2libc.c
	gcc -o ret2libc get_ebp.S ret2libc.c -m32

.PHONY: clean
clean:
	rm -fv prelim *.o
	rm -fv ret2libc *.o
	rm -fv *~ \#*\# *.swp
