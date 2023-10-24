#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int validCount = 0;

    std::ifstream file("input.txt");
    string line;

    while (std::getline(file, line)) 
    {
        string range;
        string letterRaw;
        string password;

        int lowerRange, upperRange;
        char dash;
        stringstream ss(line);
        ss >> lowerRange >> dash >> upperRange >> letterRaw >> password;

        char letter = letterRaw[0];

        int count = 0;
        for (auto x : password)
        {
            if (x == letter)
            {
                count++;
            }
        }
        
        if (count >= lowerRange && count <= upperRange)
        {
            validCount++;
        }
    }
    std::cout << validCount;
    return 0;
}