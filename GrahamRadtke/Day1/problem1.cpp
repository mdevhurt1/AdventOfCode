#include <cstdio>
#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    uint16_t ret = 0;
    uint16_t lines = 0;
    int16_t dial = 50;
    int16_t tmp = 0;
    char input[5] = { ' ' };
    
    while(cin >> input)
    {
        lines++;
        //printf("input: %s\n", input);
        if(input[0] == 'R')
        {
            tmp = atoi(&input[1]);
            //printf("dial:%d + turn:%d\n", dial, tmp);
            dial = (dial + tmp) % 100;
        }
        else
        {
            tmp = atoi(&input[1]);
            //printf("dial:%u - turn:%u\n", dial, tmp);
            dial = (dial - tmp) % 100;
        }
        
        //printf("dial:%d\n", dial);
        if(dial == 0)
        {
            ret++;
        }
    }
    
    printf("\nlines read: %u \npassword = %u\n", lines, ret);

    // My answer was 1071
    return 0;
}