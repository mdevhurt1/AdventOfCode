#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int main()
{
    string input;
    uint64_t ret = 0;
    long int lines = 0;
    
    while(cin >> input)
    {
        string tmp;
        auto prev = input.begin();
        auto end = input.end();
        
        lines++;
        
        for(int i = 12; i > 0; i--)
        {
            auto candidate = prev;
            auto curBest = prev;
            
            //printf("last char = %c\n", *(end - (i - 1)));
            
            while(candidate != (end - (i - 1)))
            {
                uint8_t cur = (*candidate - '0');
                uint8_t best = (*curBest - '0');
                
                if(cur > best)
                {
                    curBest = candidate;
                }
                
                if(cur == 9) break;
                
                candidate++;
            }
            
            tmp += *curBest;
            prev = (curBest + 1);
        }
        
        printf("line: %d - joltage = %s\n", lines, tmp.c_str());
        
        ret += stoull(tmp);
    }

    printf("total joltage = %llu\n", ret);

    // My answer was 170418192256861

    return 0;
}