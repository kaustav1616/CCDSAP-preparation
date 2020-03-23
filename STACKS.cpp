// problem link: https://www.codechef.com/problems/STACKS

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int i, j, num_tests, disc, num_discs, count;
	map<int, int> discs;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    count = 0;
	    discs.clear();
	    cin >> num_discs;
	    
	    for(j = 0; j < num_discs; ++j)
	    {
	        cin >> disc;
	        auto itr = discs.upper_bound(disc);
	        
	        if(itr != discs.end()) // there is stack head greater than current disc
	        {
	            if(itr->second == 1)
	                discs.erase(itr);
	            else
	                --itr->second;
	        }
	        
	        if(discs.find(disc) == discs.end())
	            discs.insert({disc, 1});
	        else
	            ++discs[disc];
	    }
	    
	    for(auto itr = discs.begin(); itr != discs.end(); ++itr)
	        count += itr->second;
	    
	    cout << count << " ";
	    
	    for(auto itr = discs.begin(); itr != discs.end(); ++itr)
	    {
	        for(j = 0; j < itr->second; ++j)
	            cout << itr->first << " ";
	    }
	    
	    cout << endl;
	}
	return 0;
}
