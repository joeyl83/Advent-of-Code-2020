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

    long long result1 = calculateTrees(1, 1, grid);
    long long result2 = calculateTrees(3, 1, grid);
    long long result3 = calculateTrees(5, 1, grid);
    long long result4 = calculateTrees(7, 1, grid);
    long long result5 = calculateTrees(1, 2, grid);

    long long finalResult = result1 * result2 * result3 * result4 * result5;

    cout << finalResult;

    return 0;
}

