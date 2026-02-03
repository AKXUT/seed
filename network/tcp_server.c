#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in srv_addr, cli_addr;
  char buf[100];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  memset(&srv_addr, 0, sizeof(struct sockaddr_in));
  srv_addr.sin_family = AF_INET;
  srv_addr.sin_port = htons(9090);

  bind(sockfd, (struct sockaddr *)&srv_addr, sizeof(struct sockaddr_in));

  listen(sockfd, 5);
  int cli_len = sizeof(cli_addr);

  newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);

  memset(buf, 0, sizeof(buf));
  int len = read(newsockfd, buf, 100);
  printf("Recieved %d bytes: %s\n", len, buf);

  return 0;
}
