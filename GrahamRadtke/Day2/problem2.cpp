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
        
        printf("%s - %s\n", start.c_str(), end.c_str());
        
        for(long int i = stol(start); i <= stol(end); i++)
        {
            string tmp;
            string val = to_string(i);
            
            for(int j  = 0; j < (val.length() / 2); j++)
            {
                bool isRepeat = true;
                size_t k;
                
                tmp.push_back(val[j]);
                
                //printf("j = %d - tmp = %s\n", j , tmp.c_str());
                
                for(k = tmp.length(); k <= (val.length() - tmp.length()); k += tmp.length())
                {
                    //printf("k = %d - substr = %s\n", k, val.substr(k, tmp.length()).c_str());
                    
                    if(tmp != val.substr(k, tmp.length()))
                    {
                        isRepeat = false;
                        break;
                    }
                }
                
                if(isRepeat && ((val.length() % k) == 0))
                {
                    printf("isRepeat: %d\n", i);
                    ret += i;
                    break;
                }
            }
            
        }
    }
    
    printf("sum = %ld", ret);
    
    // My answer was 31898925685
    
    return 0;
}