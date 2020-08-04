epoll-client: main.c
	cc -o epoll-client main.c -lpq -g
clean:
	rm epoll-client