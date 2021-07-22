#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

int main() {

    int sockfd;
    char buff[MAX];
    struct sockaddr_in servaddr , cliaddr ; 
    //socket creation
    sockfd = socket(AF_INET , SOCK_DGRAM , 0);

    bzero(&servaddr, sizeof(servaddr));
    bzero(&cliaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    bind(sockfd, (SA*)&servaddr, sizeof(servaddr));

    int len , n ;
    len = sizeof(cliaddr);

    while(1) 
    {
        bzero(buff, MAX); 
  
        recvfrom(sockfd, (char *)buff, MAX, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
        
        printf("Client : %s (msg length: %ld chars)\nServer : ", buff, strlen(buff)); 
        bzero(buff, MAX);
        
        scanf("%[^\n]%*c" , buff);
        sendto(sockfd, (const char *)buff, strlen(buff), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
  
        if (strncmp("exit", buff, 4) == 0) 
        { 
            printf("Connection Closed\n"); 
            break; 
        } 
    }

    return 0;
}
