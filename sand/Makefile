CC = gcc
CFLAGS = -g -O0

pipe : pipe.c helloWorld
	$(CC) $(CFLAGS) -o $@ $<

execve : execve.c helloWorld
	$(CC) $(CFLAGS) -o $@ $<

execvp : execvp.c helloWorld
	$(CC) $(CFLAGS) -o $@ $<

wait : wait.c
	$(CC) $(CFLAGS) -o $@ $^

fork : fork.c
	$(CC) $(CFLAGS) -o $@ $^

helloWorld : hello_world.c
	$(CC) $(CFLAGS) -o $@ $^

pipetest : pipetest.c
	$(CC) $(CFLAGS) -o $@ $^

