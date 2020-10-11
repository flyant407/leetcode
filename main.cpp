#include "solution.h"
#include "UndergroundSystem.h"
using namespace std;


int main() 
{
    // UndergroundSystem sys;
    // sys.checkIn(45,"Leyton",3);
    // sys.checkIn(32,"Paradise",8);
    // sys.checkIn(27,"Leyton",10);
    // sys.checkOut(45,"Waterloo",15);
    // sys.checkOut(27,"Waterloo",20);
    // sys.checkOut(32,"Cambridge",22);
    // double res;
    // res = sys.getAverageTime("Paradise","Cambridge");
    // res = sys.getAverageTime("Leyton","Waterloo");
    // sys.checkIn(10,"Leyton",24);
    // res = sys.getAverageTime("Leyton","Waterloo");
    // sys.checkOut(10,"Waterloo",38);
    // res = sys.getAverageTime("Leyton","Waterloo");

    Solution s;
    int res = s.longestCommonSubsequence("abcde", "ace");
    vector<vector<char>> board = {
{'1','1','1','1','0'},
{'1','1','0','1','0'},
{'1','1','0','0','0'},
{'0','0','0','0','0'}
};
    bool ress = s.numsIslands(board);
    return 0;
}