#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define  MAXLINE 4096

int main(int argc, char const *argv[]) {
  int sockfd, len;
  char buffer[MAXLINE];
  struct sockaddr_in  servaddr;
  FILE *fq;

  if (argc != 2) {
    printf("usage: ./client <ipaddress>\n");
    return 0;
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
    return 0;
  }

  memset(&servaddr, 0, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(6666);
   if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
     printf("inet_pton error for %s\n",argv[1]);
     return 0;
   }

   if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
     printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
     return 0;
   }
   if ((fq = fopen("/home/workdir/Photos/001.jpg","rb")) == NULL) {
     printf("File open.\n");
     close(sockfd);
     exit(1);
   }

   bzero(buffer,sizeof(buffer));
   while (!feof(fq)) {
     len = fread(buffer, 1, sizeof(buffer), fq);
     if (len != write(sockfd, buffer, len)) {
       printf("write.\n");
       break;
     }
   }
   close(sockfd);
   fclose(fq);

  return 0;
}
