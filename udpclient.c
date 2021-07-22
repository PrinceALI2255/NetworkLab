#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h>
#include <arpa/inet.h>
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

int main()
{

    int sockfd;
    char buff[MAX];
    struct sockaddr_in servaddr;
    
    //socket creation
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr)); 

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    int n, len;

    while(1) {
        bzero(buff, sizeof(buff)); 
        printf("Client : "); 
        n = 0; 
        
        scanf("%[^\n]%*c" , buff);
        sendto(sockfd, (const char *)buff, strlen(buff), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));

        bzero(buff, sizeof(buff)); 
        recvfrom(sockfd, (char *)buff, MAX, MSG_WAITALL, (struct sockaddr *) &servaddr, &len);

        printf("Server : %s (message length: %ld)\n", buff, strlen(buff));
        if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Connection Closed\n"); 
            break; 
        }
    }
    
  
    close(sockfd);

    return 0;
}
