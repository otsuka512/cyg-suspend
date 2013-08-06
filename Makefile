# Makefile
#  cyg-suspend

TARGET=cyg-suspend.exe

$(TARGET): main.o
	gcc -O2 -Wall -o $(TARGET) main.o -lpowrprof

main.o: main.c
	gcc -O2 -Wall -c -o main.o main.c

clean:
	rm -f *.o $(TARGET)
