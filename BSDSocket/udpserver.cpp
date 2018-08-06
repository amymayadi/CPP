/* udp server in C */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h> /* for close() for socket */ 
#include <stdlib.h>
 
int main(void)
{
  int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  struct sockaddr_in sa; 
  char buffer[1024];
  ssize_t recsize;
  socklen_t fromlen;
 
  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_addr.s_addr = INADDR_ANY;
  sa.sin_port = htons(7654);
 
  if (-1 == bind(sock,(struct sockaddr *)&sa, sizeof(struct sockaddr)))
  {
    perror("error bind failed");
    close(sock);
    exit(EXIT_FAILURE);
  } 
 
  for (;;) 
  {
    printf ("recv test....\n");
    recsize = recvfrom(sock, (void *)buffer, 1024, 0, (struct sockaddr *)&sa, &fromlen);
    if (recsize < 0)
      fprintf(stderr, "%s\n", strerror(errno));
    printf("recsize: %d\n ",recsize);
    sleep(1);
    printf("datagram: %s\n",buffer);
  }
}
