#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int main()
{
    string input;
    long int ret = 0;
    long int lines = 0;
    
    while(cin >> input)
    {
       auto start = input.begin();
       auto end = (input.end() - 1);
       auto firstBest = input.begin();
       auto lastBest = (input.end()  - 1);
       
       lines++;
       
       while(start != end)
       {
           uint8_t cur = (*start - '0');
           uint8_t old = (*firstBest - '0');
           
           if(cur > old)
           {
               firstBest = start;
           }
           
           if(cur == 9) break;
           
           start++;
       }
       
       while(end != firstBest)
       {
           uint8_t cur = (*end - '0');
           uint8_t old = (*lastBest - '0');
           
           if(cur > old)
           {
               lastBest = end;
           }
           
           if(cur == 9) break;
           
           end--;
       }
       
       printf("line: %d - joltage = %c%c\n", lines, *firstBest, *lastBest);
       
       ret += ((*firstBest - '0') * 10 + (*lastBest - '0'));
    }

    printf("total joltage = %d\n", ret);

    // My answer was 17100

    return 0;
}