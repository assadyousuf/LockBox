#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <sstream>
//#include <algorithm>
using namespace std;

struct person{
    std::string name;
    std::string key;
    bool valid;
    
};

bool checkIfInside(vector <string> whosInside,string name);
bool checkIfFireFighter(string key);
bool validKey(vector <string> validKeys,string key);
int input(string firstword,string secondword);
void printWhoIsInside(vector <string> whosinside);
void removeFromInisdeHouse(vector <string> *whosInside, string name);
int wordCounter(string line);
