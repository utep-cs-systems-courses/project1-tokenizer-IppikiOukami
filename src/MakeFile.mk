# Files
OBJS= tokenizer.o history.o UI.o

# compiler flags.  -g for debug, -O3 for optimization
CFLAGS= -g -O3

# first target is built by default
all: tokenize

# target
tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)
# clear dir of unnecessary files
clean:
	rm -f *.o *~ tokenize

run: tokenize
	./tokenize
