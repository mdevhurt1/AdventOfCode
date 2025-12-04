#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int ret = 0;
    int tmpRet = 0;
    string tmp;
    vector<string> map;

    while(cin >> tmp)
    {
        map.push_back(tmp);
    }

    do{
        tmpRet = 0;

        for(int i = 0; i < map.size(); i++)
        {
            for(int j = 0; j < map[i].size(); j++)
            {
                int numRolls = 0;

                if(map[i][j] != '@') continue;
    
                if(i >= 0 && i < (map.size() - 1))
                {
                    if(map[i + 1][j] == '@') ++numRolls;

                    if(j >= 0 && j < (map[i].size() - 1))
                    {
                        if(map[i + 1][j + 1] == '@') ++numRolls;
                    }

                    if(j > 0 && j <= (map[i].size() - 1))
                    {
                        if(map[i + 1][j - 1] == '@') ++numRolls;
                    }
                }

                if(i > 0 && i <= (map.size() - 1))
                {
                    if(map[i - 1][j] == '@') ++numRolls;

                    if(j >= 0 && j < (map[i].size() - 1))
                    {
                        if(map[i - 1][j + 1] == '@') ++numRolls;
                    }

                    if(j > 0 && j <= (map[i].size() - 1))
                    {
                        if(map[i - 1][j - 1] == '@') ++numRolls;
                    }
                }

                if(j >= 0 && j < (map[i].size() - 1))
                {
                    if(map[i][j + 1] == '@') ++numRolls;
                }

                if(j > 0 && j <= (map[i].size() - 1))
                {
                    if(map[i][j - 1] == '@') ++numRolls;
                }

                if(numRolls < 4)
                {
                    tmpRet++;
                    map[i][j] = '.';
                }
            }
        }

        ret += tmpRet;
    }while(tmpRet != 0);

    printf("Num Rolls  = %d\n", ret);

    // My answer was 8946

    return 0;
}