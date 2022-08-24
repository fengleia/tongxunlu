TARGET?=main
OBJS:=main.o tongxunlu.o
CC:=cc
CFLAGS:=-c -o
CFLAGSs:=-o
$(TARGET):$(OBJS)
	$(CC) $(OBJS) $(CFLAGSs) $(TARGET)
main.o:main.c
	$(CC) main.c $(CFLAGS) main.o
tongxunlu.o:tongxunlu.c
	$(CC) tongxunlu.c $(CFLAGS) tongxunlu.o

clean:
	rm $(OBJS) $(TARGET)
	
