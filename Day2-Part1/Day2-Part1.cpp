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

    string range, letter, password;

    while (std::cin >> range >> letter >> password) {
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
    }
    return 0;
}