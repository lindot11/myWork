#pragma once
#include <unordered_map>
#include <map>
#include <string>

class MsgHandler 
{
public:
    enum event {
        VALVE_POS1, VALVE_POS2, 
        CALIBRATE_W1, CALIBRATE_W2,
        CALIBRATE_STEP1, CALIBRATE_STEP2, 
        CALIBRATE_STEP3, CALIBRATE_STEP4,
        CALIBRATE_NEXT, CALIBRATE_CANCEL, 
        CALIBRATE_DONE, CALIBRATE_ERROR,
        SYRUP_W1_EMPTY, SYRUP_W1_AVAIL,
        SYRUP_W2_EMPTY, SYRUP_W2_AVAIL,
        ALARM_OFF, ALARM_ON,
        MODE_STANDBY, MODE_OPERATE, 
        MODE_CALIBRATE, MODE_RESTART,
        LIFT_ERROR, LIFT_READY,
        PSOC_ERROR, PSOC_READY,
    };

    event decodeData(const char * msg);
    const char * encodeData(event evt);

private:
    std::unordered_map<event, const char *> MsgProtocol_send {
        {VALVE_POS1, "vp 1"}, {VALVE_POS2, "vp 2"}, 
        {CALIBRATE_W1, "cw 1"}, {CALIBRATE_W2, "cw 2"},
        {CALIBRATE_NEXT, "cn"}, {CALIBRATE_CANCEL, "cc"},
        {MODE_STANDBY, "md 0"}, {MODE_OPERATE, "md 1"},
        {MODE_CALIBRATE, "md 2"}, {MODE_RESTART, "md 3"}
    };

    std::unordered_map<std::string, event> MsgProtocol_recv {
        {"vp 1", VALVE_POS1}, {"vp 2", VALVE_POS2}, 
        {"c1", CALIBRATE_STEP1}, {"c2", CALIBRATE_STEP2},
        {"c3", CALIBRATE_STEP3}, {"c4", CALIBRATE_STEP4},
        {"cd", CALIBRATE_DONE}, {"ce", CALIBRATE_ERROR},
        {"s1 0", SYRUP_W1_EMPTY}, {"s1 1", SYRUP_W1_AVAIL},
        {"s1 0", SYRUP_W2_EMPTY}, {"s1 1", SYRUP_W2_AVAIL},
        {"al 0", ALARM_OFF}, {"al 1", ALARM_ON, },
        {"lf 0", LIFT_ERROR}, {"lf 1", LIFT_READY},
        {"ps 0", PSOC_ERROR}, {"ps 1", PSOC_READY}
    };

};