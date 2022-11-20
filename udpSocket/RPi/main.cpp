#include "SocketUDP.h"
#include "SyrupMeasure.h"
#include "MsgHandler.h"
#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define PORT_NO 9000
#define PEER_ADDR "192.168.109.130"

int main(int argc, char *argv[])
{
    MsgHandler mh;

    SocketUDP sock;
    if(sock.initSocket(PORT_NO)){
        printf("Socket is ready\n");
    }
    if(sock.connectPeer(PEER_ADDR, PORT_NO)){
        printf("Connection open to peer\n");
    }
    if(sock.handshake(false)){
        printf("Handshaked with peer\n");
    }

    // SyrupMeasure syrupWeight1;
    // string weightRcvd;

    while (1) {
        /* TEST: storing syrup weight */
        // weightRcvd = sock.recvMsg();
        // if (weightRcvd.compare(0, 2, "w1") == 0) {
        //     syrupWeight1.saveMeasure(weightRcvd);
        //     cout << syrupWeight1.getWeight() << endl;
        //     cout << syrupWeight1.getTimestamp() << endl;
        //     cout << syrupWeight1.getCalendarTime() << endl;
        // }

        /* TEST: recv msg */
        if (mh.decodeData(sock.recvMsg()) == mh.VALVE_POS2) {
            cout << "valve position 2" << endl;
        }

        /* TEST: send msg */
        sock.sendMsg(mh.encodeData(mh.VALVE_POS1));

        sleep(1);
    }

    return 0;
}
