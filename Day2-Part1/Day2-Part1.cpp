#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string range = "", letter, password;
    int validCount = 0;

    while ((std::cin >> range >> letter >> password)) {
        int lowerRange = 0;
        int upperRange = 0;
        string section = "";
        for (auto x : range)
        {
            if (x == '-')
            {
                lowerRange = stoi(section);
                section = "";
            }
            else 
            {
                section = section + x;
            }
        }
        upperRange = stoi(section);

        char key = letter[0];

        int count = 0;
        for (auto x : password)
        {
            if (x == key)
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
    std::cout << "test";
    return 0;
}