MsgHandler::event MsgHandler::recvHandler(char * readMsg, struct data &database) {

    switch (readMsg[0])
    {
    case 'v':
        if (strcmp(readMsg, "vp 1") == 0) {
            database.valvePosition = 1;
        }
        else if (strcmp(readMsg, "vp 2") == 0) {
            database.valvePosition = 2;
        }
        else {
            return INVALID_MSG;
        }
        return VALVE_POSITION;
    case 's':
        if (strcmp(readMsg, "s1 0") == 0) {
            database.syrupStatus1 = 0;
            return SYRUP_STATUS1;
        }
        else if (strcmp(readMsg, "s1 1") == 0) {
            database.syrupStatus1 = 1;
            return SYRUP_STATUS1;
        }
        else if (strcmp(readMsg, "s2 0") == 0) {
            database.syrupStatus2 = 0;  
            return SYRUP_STATUS2;
        }
        else if (strcmp(readMsg, "s1 1") == 0) {
            database.syrupStatus2 = 1;
            return SYRUP_STATUS2;
        }
        else {
            return INVALID_MSG;
        }
    case 'a':
        if (strcmp(readMsg, "as 0") == 0) {
            database.alarmStatus = 0;
        }
        else if (strcmp(readMsg, "as 0") == 0) {
            database.alarmStatus = 1;
        }
        else {
            return INVALID_MSG;
        }
        return ALARM_STATUS;
    case 'l':
        if (strcmp(readMsg, "lr") == 0) {
            database.liftStatus = 0;
        }
        else if (strcmp(readMsg, "le") == 0) {
            database.liftStatus = 1;
        }
        else {
            return INVALID_MSG;
        }
        return LIFT_STATUS;
    case 'p':
        if (strcmp(readMsg, "ps 0") == 0) {
            database.psocStatus = 0;
        }
        else if (strcmp(readMsg, "ps 1") == 0) {
            database.psocStatus = 1;
        }
        else {
            return INVALID_MSG;
        }
        return PSOC_STATUS;
    case 'c':
        if (strcmp(readMsg, "c1") == 0) {
            database.calibrationStep = STEP_1;
        }        
        else if (strcmp(readMsg, "c2") == 0) {
            database.calibrationStep = STEP_2;
        }
        else if (strcmp(readMsg, "c3") == 0) {
            database.calibrationStep = STEP_3;
        }        
        else if (strcmp(readMsg, "c4") == 0) {
            database.calibrationStep = STEP_4;
        }
        else if (strcmp(readMsg, "cd") == 0) {
            database.calibrationStep = DONE;
        }        
        else if (strcmp(readMsg, "ce") == 0) {
            database.calibrationStep = ERROR;
        }
        else {
            return INVALID_MSG;
        }
        return CALIBRATION_STEP;
    default:
        return INVALID_MSG;
    }
}




    case 'm':
        if (strcmp(readMsg, "md 0") == 0) {
            database.systemMode = STANDBY;
        }
        else if (strcmp(readMsg, "md 1") == 0) {
            database.systemMode = DRIFT;
        }
        else if (strcmp(readMsg, "md 2") == 0) {
            database.systemMode = CALIBRATION;
        }
        else if (strcmp(readMsg, "md 3") == 0) {
            database.systemMode = RESTART;
        }
        else {
            return INVALID_MSG;
        }
        return SYSTEM_MODE;



struct data {
    int valvePosition;
    int syrupStatus1;
    int syrupStatus2;
    int alarmStatus;
    int systemMode;
    int calibrationStep;
    int liftStatus;
    int psocStatus;
};

            std::map<event, const char *> MsgProtocol_send {
        {VALVE_POS1, "vp 1"}, {VALVE_POS2, "vp 2"}, 
        {CALIBRATE_W1, "cw 1"}, {CALIBRATE_W2, "cw 2"},
        {CALIBRATE_STEP1, "c1"}, {CALIBRATE_STEP2, "c2"},
        {CALIBRATE_STEP3, "c3"}, {CALIBRATE_STEP4, "c4"},
        {CALIBRATE_NEXT, "cn"}, {CALIBRATE_CANCEL, "cc"},
        {CALIBRATE_DONE, "cd"}, {CALIBRATE_ERROR, "ce"},
        {SYRUP_W1_EMPTY, "s1 0"}, {SYRUP_W1_AVAIL, "s1 1"},
        {SYRUP_W2_EMPTY, "s1 0"}, {SYRUP_W2_AVAIL, "s1 1"},
        {ALARM_OFF, "al 0"}, {ALARM_ON, "al 1"},
        {MODE_STANDBY, "md 0"}, {MODE_OPERATE, "md 1"},
        {MODE_CALIBRATE, "md 2"}, {MODE_RESTART, "md 3"},
        {LIFT_ERROR, "lf 0"}, {LIFT_READY, "lf 1"},
        {PSOC_ERROR, "ps 0"}, {PSOC_READY, "ps 1"}
    };

    std::map<const char *, event> MsgProtocol_recv {
        {"vp 1", VALVE_POS1}, {"vp 2", VALVE_POS2}, 
        {"cw 1", CALIBRATE_W1}, {"cw 2", CALIBRATE_W2},
        {"c1", CALIBRATE_STEP1}, {"c2", CALIBRATE_STEP2},
        {"c3", CALIBRATE_STEP3}, {"c4", CALIBRATE_STEP4},
        {"cn", CALIBRATE_NEXT}, {"cc", CALIBRATE_CANCEL},
        {"cd", CALIBRATE_DONE}, {"ce", CALIBRATE_ERROR},
        {"s1 0", SYRUP_W1_EMPTY}, {"s1 1", SYRUP_W1_AVAIL},
        {"s1 0", SYRUP_W2_EMPTY}, {"s1 1", SYRUP_W2_AVAIL},
        {"al 0", ALARM_OFF}, {"al 1", ALARM_ON, },
        {"md 0", MODE_STANDBY}, {"md 1", MODE_OPERATE},
        {"md 2", MODE_CALIBRATE}, {"md 3", MODE_RESTART},
        {"lf 0", LIFT_ERROR}, {"lf 1", LIFT_READY},
        {"ps 0", PSOC_ERROR}, {"ps 1", PSOC_READY}
    };