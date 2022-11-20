#include "SyrupMeasure.h"
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void SyrupMeasure::saveMeasure(string msg){
    weight_ = stod(msg.substr(3, 7));
    timestamp_ = time(NULL);
    calendarTime_ = ctime(&timestamp_);
}

double SyrupMeasure::getWeight() const {
    return weight_;
}

time_t SyrupMeasure::getTimestamp() const {
    return timestamp_;
}
char * SyrupMeasure::getCalendarTime() const {
    return calendarTime_;
}