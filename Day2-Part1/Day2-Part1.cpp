#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    fstream file;
    file.open("input.txt", ios::in);

    vector<string> a;
    string line;

    while (!file.eof())
    {
        file >> line;
        a.push_back(line);
    }
    file.close();

    for (int i = 0; i < a.size(); i++)
    {
        int j = 0;
        stringstream ssin(a[i]);
        while (ssin.good() && i < 3) 
        {

        }
    }
}