#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    fstream input("input.txt");
    string line;
    vector<string> grid;
    while (getline(input, line))
    {
        grid.push_back(line);
    }

    int treeCount = 0;
    const size_t ROW_SIZE = grid[0].length();

    int c = 3;
    for (int r = 1; r < grid.size(); r++)
    {
        if (grid[r][c] == '#')
        {
            treeCount++;
        }
        c = (c + 3) % ROW_SIZE;
    }
    cout << treeCount;
}
