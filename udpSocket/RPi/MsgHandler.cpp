#include "MsgHandler.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const char * MsgHandler::encodeData(event evt) {
    return MsgProtocol_send.at(evt);
}

MsgHandler::event MsgHandler::decodeData(const char * msg) {
    return MsgProtocol_recv.at(msg);
}