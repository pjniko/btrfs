OBJS = main.o factory.o iconoverlay.o contextmenu.o

INCLUDES = -I/usr/i686-w64-mingw32/usr/include/ddk

CFLAGS = -Wall $(INCLUDES)

LIBS = -lole32 -luuid

CC = i686-w64-mingw32-g++

all: ../../x86/shellbtrfs.dll

main.o: main.cpp factory.h
	$(CC) $(CFLAGS) -c -o $@ $<

factory.o: factory.cpp factory.h iconoverlay.h
	$(CC) $(CFLAGS) -c -o $@ $<

iconoverlay.o: iconoverlay.cpp iconoverlay.h
	$(CC) $(CFLAGS) -c -o $@ $<

contextmenu.o: contextmenu.cpp contextmenu.h
	$(CC) $(CFLAGS) -c -o $@ $<

../../x86/shellbtrfs.dll: $(OBJS)
	$(CC) -shared -static-libgcc -o $@ $(OBJS) $(LIBS) -Wl,--kill-at

clean:
	rm -f *.o ../../x86/shellbtrfs.dll

