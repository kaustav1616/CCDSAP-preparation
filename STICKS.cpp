// problem link: https://www.codechef.com/problems/STICKS

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(int, int);

int main() 
{
	int num_tests, num_sticks, i, j, num, count, prod;
	vector<int> sticks;
	unordered_map<int, int> stick_count;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    sticks.clear();
	    stick_count.clear();
	    count = 0;
	    prod = 1;
	    cin >> num_sticks;
	    
	    for(j = 0; j < num_sticks; ++j)
	    {
	        cin >> num;
	        
	        if(stick_count.find(num) == stick_count.end())
	        {
	            sticks.push_back(num);
	            stick_count.insert({num, 1});
	        }
	        else
	            ++stick_count[num];
	    }
	    
	    sort(sticks.begin(), sticks.end(), cmp);
	    
	    for(j = 0; j < sticks.size(); ++j)
	    {
	        if(stick_count[sticks[j]] >= 4)
	        {
	            if(!count)
	            {
	                prod = sticks[j] * sticks[j];
	                count += 2;
	            }
	            else
	            {
	                prod *= sticks[j];
	                ++count;
	            }
	        }
	        else if(stick_count[sticks[j]] >= 2)
	        {
	            prod *= sticks[j];
	            ++count;
	        }
	        
	        if(count == 2)
	            break;
	    }
	    
	    if(count < 2)
	        cout << -1 << endl;
	    else
	        cout << prod << endl;
	}
	
	return 0;
}

bool cmp(int i, int j)
{
    return (i > j);
}
