#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in dest;
  memset(&dest, 0, sizeof(struct sockaddr_in));

  dest.sin_family = AF_INET;
  dest.sin_addr.s_addr = inet_addr("10.9.0.6");
  dest.sin_addr.s_addr = inet_addr("10.9.0.6");

  connect(sockfd, (struct  sockaddr *)&dest, sizeof(struct sockaddr_in));

  char *buff1 = "Hello Server!\n";
  char *buff2 = "Hello Again!\n";
  
  write(sockfd, buff1, strlen(buff1));
  write(sockfd, buff2, strlen(buff2));

  return 0;
}
