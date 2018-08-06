#include <zmq.h>  
#include <stdio.h>  
#include <unistd.h>  
#include <string.h>  
#include <assert.h>  
  
int main (void)  
{  
    //  Socket to talk to clients  
    void *context = zmq_ctx_new ();  
    void *responder = zmq_socket (context, ZMQ_REP);  
    int rc = zmq_bind (responder, "tcp://*:5555");  
    assert (rc == 0);  
  
    char buffer [10];  
    char *send_s = "World";  
    while (1) {  
        // 接收消息  
        zmq_recv (responder, buffer, 10, 0);  
        buffer[5] = 0;  
        printf ("Recv %s\n", buffer);  
        // 发送反馈  
        zmq_send (responder, send_s, 5, 0);  
        printf ("Send %s\n", send_s);  
        sleep(1);  
    }  
    return 0;  
} 
