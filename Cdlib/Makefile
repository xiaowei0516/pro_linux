CC = gcc


%o : %c
		gcc -c -o $@ -fPIC $<

main : main.o libcar.so
		gcc -o $@ $< -rdynamic -ldl
libcar.so : trunk.o
		gcc -o $@ -shared $<

clean:
		rm -rf *.o *.so main
