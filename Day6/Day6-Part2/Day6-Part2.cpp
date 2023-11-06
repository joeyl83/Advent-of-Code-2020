#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool searchForChar(string list, char key)
{
    if (list.size() == 0)
    {
        return false;
    }

    for (char x : list)
    {
        if (x == key)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    fstream input("input.txt");
    string line;
    int total = 0;
    vector<char> allCharList;
    bool firstLine = true;
    while (getline(input, line))
    {
        if (firstLine)
        {
            for (char x : line)
            {
                allCharList.push_back(x);
            }
            firstLine = false;
        }
        else if (!line.empty())
        {
            for (int i = 0; i < allCharList.size(); i++)
            {
                if (!searchForChar(line, allCharList[i]))
                {
                    allCharList.erase(allCharList.begin() + i);
                }
            }
        }
        else
        {
            total += allCharList.size();
            std::cout << allCharList.size() << '\n';
            allCharList.clear();
            firstLine = true;
        }
    }
    total += allCharList.size();
    std::cout << total;
}
