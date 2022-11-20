#include "SocketUDP.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>

void SocketUDP::error(const char * errPoint)
{
    perror(errPoint);
    //exit(EXIT_FAILURE);
}

bool SocketUDP::initSocket(int portNo) {
    sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd_ < 0) {
        error("socket");
        return false;
    }
    struct timeval tv = {
        .tv_sec = 10
    };
    if (setsockopt(sockfd_, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        error("setsocktopt");
        return false;
    }
    int thisAddrLen = sizeof(thisAddr_);
    bzero(&thisAddr_, thisAddrLen);
    thisAddr_.sin_family = AF_INET;
    thisAddr_.sin_addr.s_addr = INADDR_ANY;
    thisAddr_.sin_port = htons(portNo);
    if (bind(sockfd_, (struct sockaddr *)&thisAddr_, thisAddrLen) < 0) {
        error("bind");
        return false;
    }
    return true;
}

bool SocketUDP::connectPeer(const char * ipAddr, int portNo) {
    int perrAddrLen = sizeof(peerAddr_);
    bzero(&peerAddr_, perrAddrLen);
    peerAddr_.sin_family = AF_INET;
    peerAddr_.sin_addr.s_addr = inet_addr(ipAddr);
    peerAddr_.sin_port = htons(portNo);
    if (connect(sockfd_, (struct sockaddr *)&peerAddr_, perrAddrLen) < 0) {
        error("connect");
        return false;
    }
    return true;
}

bool SocketUDP::handshake(bool initiate) {
    if (initiate) {
        if (send(sockfd_, "ok", 2, 0) < 0) {
            error("send handshake");
            return false;
        }          
        if (recv(sockfd_, rxBuf_, BUFSIZE, 0) < 0) {
            error("recv handshake");
            return false;
        } 
    }
    else {
        if (recv(sockfd_, rxBuf_, BUFSIZE, 0) < 0) {
            error("recv handshake");
            return false;
        }   
        if (send(sockfd_, "ok", 2, 0) < 0) {
            error("send handshake");
            return false;
        }  
    }     
    return true;
}

bool SocketUDP::recvACK() {
    if (recv(sockfd_, rxBuf_, BUFSIZE, 0) < 0) {
        error("recvACK");
        return false;
    }   
    if (strncmp(rxBuf_, "ak", 2) != 0) {
        return false;
    }
    return true;
}

void SocketUDP::sendACK(bool ack) {
    int nBytes;
    if (ack) {
        nBytes = send(sockfd_, "ak", 2, 0);
    }
    else {
        nBytes = send(sockfd_, "nk", 2, 0);
    }
    if (nBytes  < 0) {
        error("sendACK");
    }  
}

const char * SocketUDP::recvMsg() {
    int nBytes;
    nBytes = recv(sockfd_, rxBuf_, BUFSIZE, 0);
    if (nBytes  < 0) {
        error("recvMsg");
        bzero(rxBuf_, BUFSIZE);
        return rxBuf_;
    }   
    rxBuf_[nBytes] = '\0';
    return rxBuf_;
}

void SocketUDP::sendMsg(const char * msg) {
    if (send(sockfd_, msg, BUFSIZE, 0) < 0) {
        error("sendMsg");
    }   
}

