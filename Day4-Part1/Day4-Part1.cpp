#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    fstream input("input.txt");
    string line;
    int validCount = 0;
    int dataCount = 0;
    while (getline(input, line))
    {
        if (!line.empty())
        {
		    stringstream ss(line);
			string data;
			while (ss >> data)
			{
				string field = string() + data[0] + data[1] + data[2];
				if (field != "cid")
				{
					dataCount++;
				}
			}
        }
        else
        {
            if (dataCount == 7)
            {
                validCount++;
            }
            dataCount = 0;
        }
    }
    if (dataCount == 7)
    {
        validCount++;
    }
    cout << validCount;
}