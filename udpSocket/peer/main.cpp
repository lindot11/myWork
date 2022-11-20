#include "SocketUDP.h"
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

#define PORT_NO 9000
#define PEER_ADDR "192.168.109.133"

int main(int argc, char *argv[])
{
    SocketUDP sock;
    if(sock.initSocket(PORT_NO)){
        printf("Socket is ready\n");
    }
    if(sock.connectPeer(PEER_ADDR, PORT_NO)){
        printf("Connection open to peer\n");
    }
    if(sock.handshake(true)){
        printf("Handshaked with peer\n");
    }

    while (1) {
        /* TEST: send syrup weight */
        // sock.sendMsg("w1 11.0994");

        /*TEST: send msg */
        sock.sendMsg("vp 2");

        /* TEST: recvd msg */
        printf("%s\n", sock.recvMsg());

        sleep(1);
    }

    return 0;
}