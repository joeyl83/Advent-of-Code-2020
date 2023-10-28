#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    fstream input("input.txt");
    string line;
    vector<int> idList;

    while (getline(input, line))
    {
        int row = 0;
        int power = 6;
        for (int i = 0; i < 7; i++)
        {
            if (line[i] == 'B')
            {
                row += pow(2, power);
            }
            power--;
        }

        int col = 0;
        power = 2;
        for (int i = 7; i < 10; i++)
        {
            if (line[i] == 'R')
            {
                col += pow(2, power);
            }
            power--;
        }

        int id = row * 8 + col;
        
        idList.push_back(id);
    }

    sort(idList.begin(), idList.end());
    int num = idList[0];
    int missingNum;
    for (int i = 0; i < idList.size(); i++)
    {
        if (idList[i] != num)
        {
            missingNum = num;
            break;
        }
        num++;
    }
    cout << missingNum << '\n';
}