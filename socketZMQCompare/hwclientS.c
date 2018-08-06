#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <string.h>  
#include <arpa/inet.h>  
  
#define PORTNUM 6666  
#define BUFFSIZE 32  
#define die(err) { perror(err); exit(1); }  
  
int main(void)  
{  
    int c_sock;  
    struct sockaddr_in c_addr;  
    char buffer[BUFFSIZE];  
    int msgcount, received;  
  
    if ((c_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {  
        die("failed to create socket");  
    }  
  
    memset(&c_addr, 0, sizeof(c_addr));  
    c_addr.sin_port = htons(PORTNUM);  
    c_addr.sin_family = AF_INET;  
      
    if (connect(c_sock, (struct sockaddr *)&c_addr, sizeof(c_addr)) < 0) {  
        die("failed to connect");  
    }  
  
    msgcount = 0;  
    char *send_s = "Hello";  
    int len_i = strlen(send_s);  
    while (msgcount < 10) {  
        received = 0;  
        // 发送消息  
        if (send(c_sock, send_s, len_i, 0) != len_i) {  
            die("failed to send");  
        }  
        printf("Send %s\n", send_s);  
        // 接收反馈  
        while(received < len_i){  
            int bytes = 0;  
            if ((bytes = recv(c_sock, buffer, BUFFSIZE-1, 0)) < 1) {  
                die("failed to recv");  
            }  
            received += bytes;  
            buffer[bytes] = '\0';  
            printf("Recv %s\n", buffer);  
        }  
        msgcount++;  
    }  
  
    close(c_sock);  
    return 0;  
}
