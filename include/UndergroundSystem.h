#ifndef _UNDERGROUND_SYSTEM_H
#define _UNDERGROUND_SYSTEM_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

class UndergroundSystem {
public:
    UndergroundSystem(){};
    void checkIn(int id, std::string stationName, int t);
    void checkOut(int id, std::string stationName, int t);
    double getAverageTime(std::string startStation, std::string endStation);
private:
    std::map<int, std::vector<std::pair<std::string, int>>> checkInMap;
    std::map<std::string, std::vector<std::vector<int>>> checkOutMap;
};

#endif

