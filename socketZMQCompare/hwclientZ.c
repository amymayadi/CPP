#include <zmq.h>  
#include <string.h>  
#include <stdio.h>  
#include <unistd.h>  
  
#define SERVER_ENDPOINT "tcp://localhost:5555"  
#define REQUEST_TIMEOUT 3000 // msecs, (> 1000!)  
#define REQUEST_RETRIES 3 // retry before we abandon  
  
void *zmq_socket_new (void *context)  
{  
    int linger = 1;  
    void *zsocket = zmq_socket (context, ZMQ_REQ);  
    zmq_setsockopt(zsocket, ZMQ_LINGER, &linger, sizeof(linger));  
    zmq_connect (zsocket, SERVER_ENDPOINT);  
    return zsocket;  
}  
  
int main (void)  
{  
    void *context = zmq_ctx_new ();  
    void *zsocket = zmq_socket_new(context);  
  
    char buffer [255];  
    char *send_s = "Hello";  
    int retries_left = REQUEST_RETRIES;  
  
    while (retries_left) {  
        // 发送消息  
        zmq_send (zsocket, send_s, strlen(send_s), 0);  
        printf ("Send %s\n", send_s);  
        // 重试次数  
        int expect_reply = 1;  
        while (expect_reply) {  
            // 停止重试  
            if (retries_left == 0) {  
                printf("Server offline, abandoning ...\n");  
                break;  
            }  
            // 多路复用  
            zmq_pollitem_t items [] = { { zsocket, 0, ZMQ_POLLIN, 0 } };  
            int rc = zmq_poll (items, 1, REQUEST_TIMEOUT);  
            if (rc == -1) break; // Interrupted  
            if (items [0].revents & ZMQ_POLLIN) {  
                // 接收反馈  
                int size = zmq_recv (zsocket, buffer, 10, 0);  
                if (size > 255) size = 255;  
                buffer[size] = 0;  
                printf ("Recv %s\n", buffer);  
                if (buffer) {  
                    retries_left = REQUEST_RETRIES;  
                    expect_reply = 0;  
                }  
            }  
            // 重试连接  
            else {  
                printf("Retry connecting ...\n");  
                zmq_close (zsocket);  
                zsocket = zmq_socket_new(context);  
                // 重发消息  
                zmq_send (zsocket, send_s, strlen(send_s), 0);  
                printf ("Send %s\n", send_s);  
                --retries_left;  
            }  
        }  
    }  
    zmq_close (zsocket);  
    zmq_ctx_destroy (context);  
    return 0;  
}  
