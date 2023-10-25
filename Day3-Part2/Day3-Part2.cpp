#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int calculateTrees(int right, int down, vector<string> slope)
{
    int treeCount = 0;
    const size_t ROW_SIZE = slope[0].length();
    int c = right;
    for (int r = down; r < slope.size(); r = r + down)
    {
        if (slope[r][c] == '#')
        {
            treeCount++;
        }
        c = (c + right) % ROW_SIZE;
    }
    return treeCount;
}

int main()
{
    fstream input("input.txt");
    string line;
    vector<string> grid;
    while (getline(input, line))
    {
        grid.push_back(line);
    }
    cout << calculateTrees(3, 1, grid) << '\n';

    cout << (calculateTrees(1, 1, grid) * calculateTrees(3, 1, grid) * calculateTrees(5, 1, grid) * calculateTrees(7, 1, grid) * calculateTrees(1, 2, grid));

    return 0;
}

