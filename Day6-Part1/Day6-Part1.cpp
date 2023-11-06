#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool searchForChar(vector<char> list, char key)
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
    vector<char> uniqueCharList;

    while (getline(input, line))
    {
        if (!line.empty())
        {
            for (char x : line)
            {
                if (!searchForChar(uniqueCharList, x))
                {
                    uniqueCharList.push_back(x);
                }
            }
        }
        else
        {
            total += uniqueCharList.size();
            uniqueCharList.clear();
        }
    }
    total += uniqueCharList.size();
    cout << total;
}
