#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int main()
{
    long int ret = 0;
    string start, end;
    
    while(getline(cin, start, '-'))
    {
        getline(cin, end, ',');
        
        //printf("%s - %s\n", start.c_str(), end.c_str());
        
        for(long int i = stol(start); i <= stol(end); i++)
        {
            bool isRepeat = true;
            string tmp = to_string(i);
            int half = tmp.length() / 2;
            
            if((tmp.length() % 2) != 0) continue;
            
            
            for(int j = 0; j < half; j++)
            {
                if(tmp[j] != tmp[j + half])
                {
                    isRepeat = false;
                    break;
                }
            }
            
            if(isRepeat)
            {
                //printf("isRepeat: %d\n", i);
                ret += i;
            }
        }
    }
    
    printf("sum = %ld", ret);
    
    // My answer was 30608905813
    
    return 0;
}