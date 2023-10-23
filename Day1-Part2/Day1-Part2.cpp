#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    fstream my_file;
    my_file.open("input.txt", ios::in);

    vector<int> a;
    string line;

    while (!my_file.eof())
    {
        my_file >> line;
        a.push_back(stoi(line));
    }
    my_file.close();

    for (int i = 0; i < a.size() - 2; i++)
    {
        for (int j = i + 1; j < a.size() - 1; j++)
        {
            for (int k = j + 1; k < a.size(); k++)
            {
                if (a[i] + a[j] + a[k] == 2020)
                {
                    cout << a[i] * a[j] * a[k];
                }
            }
        }
    }
}
