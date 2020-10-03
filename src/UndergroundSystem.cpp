#include "UndergroundSystem.h"

using namespace std;

void UndergroundSystem::checkIn(int id, string stationName, int t) 
{  
    pair<string, int> val = make_pair(stationName, t);
    checkInMap[id].push_back(val);
}

void UndergroundSystem::checkOut(int id, string stationName, int t) 
{
    vector<int> val = {id, t};
    checkOutMap[stationName].push_back(val);
}

double UndergroundSystem::getAverageTime(string startStation, string endStation)
{
    double ret;
    vector<vector<int>> outPepole = checkOutMap[endStation];
    int num = 0;
    int totalTime = 0;
    for (int i = 0; i < outPepole.size(); i++) {
        int id = outPepole[i][0];
        int t = outPepole[i][1];
        for (int j = 0; j < checkInMap[id].size(); j++) {
            if (checkInMap[id][j].first == startStation) {
                if (checkInMap[id][j].second < t && ((j + 1) == checkInMap[id].size() || checkInMap[id][j + 1].second > t)) {
                    num++;
                    totalTime += (t - checkInMap[id][j].second);
                }
            } 
        }
    }

    ret = static_cast<double>(totalTime)/static_cast<double>(num);
    return ret;
}