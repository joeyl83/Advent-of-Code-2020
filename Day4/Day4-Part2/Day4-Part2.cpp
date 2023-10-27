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
                string info = data.substr(4);

                if (field == "byr") 
                {
                    int birthYear = stoi(info);
                    if (birthYear >= 1920 && birthYear <= 2002)
                    {
                        dataCount++;
                    }
                }
                else if (field == "iyr")
                {
                    int issueYear = stoi(info);
                    if (issueYear >= 2010 && issueYear <= 2020)
                    {
                        dataCount++;
                    }
                }
                else if (field == "eyr")
                {
                    int expYear = stoi(info);
                    if (expYear >= 2020 && expYear <= 2030)
                    {
                        dataCount++;
                    }
                }
                else if (field == "hgt")
                {
                    stringstream split(info);
                    int val;
                    string metric;
                    split >> val >> metric;
                    if ((metric == "cm" && val >= 150 && val <= 193) || (metric == "in" && val >= 59 && val <= 76))
                    {
                        dataCount++;
                    }
                }
                else if (field == "hcl")
                {
                    if (info[0] == '#' && info.length() == 7)
                    {
                        bool valid = true;
                        for (int i = 1; i < info.length(); i++)
                        {
                            if (!isdigit(info[i]) && !isalpha(info[i]))
                            {
                                valid = false;
                                break;
                            }
                        }
                        if (valid)
                        {
                            dataCount++;
                        }
                    }
                }
                else if (field == "ecl")
                {
                    if (info == "amb" || info == "blu" || info == "brn" || info == "gry" || info == "grn" || info == "hzl" || info == "oth")
                    {
                        dataCount++;
                    }
                }
                else if (field == "pid")
                {
                    if (info.length() == 9)
                    {
                        bool valid = true;
                        for (char x : info)
                        {
                            if (!isdigit(x))
                            {
                                valid = false;
                                break;
                            }
                        }
                        if (valid)
                        {
                            dataCount++;
                        }
                    }
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