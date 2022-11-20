#pragma once
#include <time.h>
#include <string>

class SyrupMeasure 
{
public:
    void saveMeasure(std::string msg);
    double getWeight() const;
    time_t getTimestamp() const;
    char * getCalendarTime() const;
private:
    double weight_;
    time_t timestamp_;
    char * calendarTime_;
};

