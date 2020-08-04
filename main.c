#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/epoll.h>
#include <unistd.h>    // for close()
#include <string.h>    // for strncmp
#include <sys/un.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>

char message[] = "Hello there!\n";
char message1[] = "fgdfg!\n";
char buf[sizeof(message)];

int main() {
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555); // или любой другой порт...
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        exit(2);
    }

    send(sock, message, sizeof(message), 0);
    close(sock);

    return 0;
}