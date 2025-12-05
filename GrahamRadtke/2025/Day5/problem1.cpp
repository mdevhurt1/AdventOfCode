#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Range
{
    uint64_t lowerBound;
    uint64_t upperBound;

    Range(uint64_t lB, uint64_t uB) : lowerBound(lB), upperBound(uB) {}
};

struct Range_less_than
{
    inline bool operator() (const Range& range1, const Range& range2)
    {
        return range1.lowerBound < range2.lowerBound;
    }
};

int main()
{
    uint64_t ret = 0;
    vector<Range> ranges;
    string input;

    while(getline(cin, input, '\n') && (input.length() > 1))
    {
        size_t hypen = input.find('-');
        Range tmpRange(stoul(input.substr(0, hypen)), stoul(input.substr(hypen+1)));
        
        // printf("lower:%lu - upper:%lu\n", tmpRange.lowerBound, tmpRange.upperBound);

        if(ranges.size() == 0)
        {
            ranges.push_back(tmpRange);
            continue;
        }

        vector<Range>::iterator it;
        for(it = ranges.begin(); it != ranges.end(); it++)
        {
            if(tmpRange.lowerBound > ((*it).upperBound + 1)) continue;

            if(tmpRange.lowerBound >= (*it).lowerBound && tmpRange.lowerBound <= (*it).upperBound)
            {
                if((*it).upperBound < tmpRange.upperBound)
                {
                    if(it != (ranges.end() - 1) && tmpRange.upperBound >= (*(it + 1)).lowerBound)
                    {
                        (*it).upperBound = (*(it + 1)).upperBound;
                        ranges.erase((it + 1));
                    }
                    else
                    {
                        (*it).upperBound = tmpRange.upperBound;
                    }
                }

                break;
            }
            else if(tmpRange.lowerBound <= (*it).lowerBound && tmpRange.upperBound >= (*it).lowerBound)
            {
                (*it).lowerBound = tmpRange.lowerBound;

                if((*it).upperBound < tmpRange.upperBound)
                {
                    if(it != (ranges.end() - 1) && tmpRange.upperBound >= (*(it + 1)).lowerBound)
                    {
                        (*it).upperBound = (*(it + 1)).upperBound;
                        ranges.erase((it + 1));
                    }
                    else
                    {
                        (*it).upperBound = tmpRange.upperBound;
                    }
                }

                break;
            }
            else if(tmpRange.lowerBound == ((*it).upperBound + 1))
            {
                if(it != (ranges.end() - 1) && tmpRange.upperBound >= (*(it + 1)).lowerBound)
                {
                    (*it).upperBound = (*(it + 1)).upperBound;
                    ranges.erase((it + 1));
                }
                else
                {
                    (*it).upperBound = tmpRange.upperBound;
                }
                break;
            }
            else if((tmpRange.upperBound + 1) == (*it).lowerBound)
            {
                (*it).lowerBound = tmpRange.lowerBound;
                break;
            }
        }

        if(it == ranges.end())
        {
            ranges.push_back(tmpRange);
        }

        sort(ranges.begin(), ranges.end(), Range_less_than());
    }

    while(cin >> input)
    {
        uint64_t tmpID = stoul(input);

        for(auto it = ranges.begin(); it != ranges.end(); it++)
        {
            if(tmpID > (*it).upperBound) continue;

            if(tmpID >= (*it).lowerBound && tmpID <= (*it).upperBound)
            {
                ret++;
                break;
            }
        }
    }

    printf("Number of available fresh ingredient IDs = %lu\n", ret);

    // My answer was 761

    return 0;
}