
main: history.o tokenizer.o uimain.o
	gcc -o main history.o tokenizer.o uimain.o

$(OBJS): history.h tokenizer.h 

clean:
	rm -f *.o main

run: main
	./main
