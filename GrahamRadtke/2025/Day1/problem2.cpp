#include <stdio.h>
#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    uint32_t ret = 0;
    int16_t dial = 50;
    int16_t tmp = 0;
    char input[4] = { ' ' };
    
    while(cin >> input)
    {
        //printf("ret: %d - dial: %d - input: %s\n", ret, dial, input);
        
        if(input[0] == 'R')
        {
            tmp = atoi(&input[1]);
            
            //printf("dial:%d + turn:%d\n", dial, tmp);
            
            ret += (tmp/100);
    
            if(dial < 0)
            {
                ret += (dial + (tmp%100)) >= 0 ? 1 : 0;
            }
            else
            {
                ret += (dial + (tmp%100)) >= 100 ? 1 : 0;  
            }
            
            dial = (dial + tmp) % 100;
        }
        else
        {
            tmp = atoi(&input[1]);
            
            //printf("dial:%u - turn:%u\n", dial, tmp);
            
            ret += (tmp/100);
    
            if(dial > 0)
            {
                ret += (dial - (tmp%100)) <= 0 ? 1 : 0;
            }
            else
            {
                ret += (dial - (tmp%100)) <= -100 ? 1 : 0;  
            }
            
            dial = (dial - tmp) % 100;
        }
    }
    
    printf("\npassword = %u\n", ret);

    // My answer was 6700

    return 0;
}