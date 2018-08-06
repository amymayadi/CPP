#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <string.h>  
#include <arpa/inet.h>  
  
#define PORTNUM 6666  
#define CONNMAX 5  
#define BUFFSIZE 32  
#define die(err) { perror(err); exit(1); }  
  
void c_action(int sock)  
{  
    char buffer[BUFFSIZE];  
    int received = -1;  
    char *send_s = "World";  
    // 接收消息  
    while ((received = recv(sock, buffer, BUFFSIZE, 0)) > 0) {  
        buffer[received] = 0;  
        printf ("Recv %s\n", buffer);  
        // 发送反馈  
        if (send(sock, send_s, received, 0) != received) {  
            die("failed to send");  
        }  
        printf ("Send %s\n", send_s);  
        sleep(1);  
    }  
    close(sock);  
}  
  
int main(void)  
{  
    struct sockaddr_in s_addr, c_addr;  
    int s_sock, c_sock;  
  
    if ((s_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {  
        die("failed to create socket");  
    }  
  
    memset(&s_addr, 0, sizeof(s_addr));  
    s_addr.sin_port = htons(PORTNUM);  
    s_addr.sin_family = AF_INET;  
  
    if (bind(s_sock, (struct sockaddr *)&s_addr, sizeof(s_addr)) < 0) {  
        die("failed to bind");  
    }  
  
    if (listen(s_sock, CONNMAX) < 0) {  
        die("failed to listen");  
    }  
  
    while (1) {  
        unsigned int c_addr_len = sizeof(c_addr);  
        if ((c_sock = accept(s_sock, (struct sockaddr *)&c_addr, &c_addr_len)) < 0) {  
            die("failed to accept");  
        }  
        c_action(c_sock);  
    }  
  
    close(s_sock);  
    return 0;  
} 
