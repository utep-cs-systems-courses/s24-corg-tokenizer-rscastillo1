OBJS = uimain.o tokenizer.o
CFLAGS = -g -O3
all: mytokens
mytokens: $(OBJS)
	cc -o mytokens $(CFLAGS) $(OBJS)
$(OBJS): tokenizer.h
clean: rm -f *.o mytokens
run: mytoken ./mytokens
