#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream input("input.txt");
    string line;
    int maxId = 0;

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
        if (id > maxId)
        {
            maxId = id;
        }
    }
    cout << maxId << '\n';
}