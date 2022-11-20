#pragma once
#include <netinet/in.h>
#define BUFSIZE 255

class SocketUDP
{
public:
    bool initSocket(int portNo);
    bool connectPeer(const char * ipAddr, int portNo);
    bool handshake(bool initiate);
    bool recvACK();
    void sendACK(bool ack);
    char * recvMsg();
    void sendMsg(const char * msg);

private:
    void error(const char * errPoint);
    int sockfd_;
    char rxBuf_[BUFSIZE];
    struct sockaddr_in thisAddr_;
    struct sockaddr_in peerAddr_;
};